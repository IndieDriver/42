$(document).ready(function(){
	$('#New').click(function(){
		var newtodo = prompt("Nouveau TODO?");
		if (!!newtodo)
		{
			var ft_list = $('#ft_list');
			var div = $('<div>').html(newtodo.toString());
			div.click(function () {
				var newtodo = prompt("Supprimer ? (y/n)");
				if (!!newtodo)
				{
					if (newtodo == "y")
					{
						$(this).remove();
						create_cookies();
					}
				}
			});
			ft_list.prepend(div);
			create_cookies();
		}
	});

	function create_cookies()
	{
		var date = new Date();
		date.setHours(date.getHours() + 24);
		var ft_list = $('#ft_list').children();
		var value = "";
		ft_list.each(function(){
			var elem = this.textContent;
			value = value + elem + "||";
		});
		document.cookie = "todo="+ value +"; expires="+ date.toGMTString()+"; path=/";
	}

	function read_cookies() {
		var cookie = document.cookie.split(';');
		for(var i = 0; i < cookie.length; i++)
		{
			var c = cookie[i];
			while (c.charAt(0)==' ') c = c.substring(1, c.length);
				if (c.indexOf("todo=") == 0)
					return c.substring("todo=".length, c.length);
		}
		return null;
	}

	var cookie = read_cookies();
	if (cookie != null)
	{
		var list = cookie.split('||');
		for (var i = list.length - 1; i >= 0; i--)
		{
			var text = list[i];
			if (text != "")
			{
				var ft_list = $('#ft_list');
				var div = $('<div>').html(text.toString());
				div.click(function () {
					var newtodo = prompt("Supprimer ? (y/n)");
					if (!!newtodo)
					{
						if (newtodo == "y")
						{
							$(this).remove();
							create_cookies();
						}
					}
				});
				ft_list.append(div);
				create_cookies();
			}
		}
	}
});
