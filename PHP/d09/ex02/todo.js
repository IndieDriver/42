function fctnew()
{
	var newtodo = prompt("Nouveau TODO?");
	if (!!newtodo)
	{
		var ft_list = document.getElementById("ft_list");
		var div = document.createElement("div");
		div.onclick = function () {
			var newtodo = prompt("Supprimer ? (y/n)");
			if (!!newtodo)
			{
				if (newtodo == "y")
				{
					this.parentNode.removeChild(this);
					create_cookies();
				}
			}
		};
		var newtodo = document.createTextNode(newtodo);
		div.appendChild(newtodo);
		ft_list.insertBefore(div, ft_list.childNodes[0]);
		create_cookies();
	}
}

function create_cookies()
{
	var date = new Date();
	date.setHours(date.getHours() + 24);
	var ft_list = document.getElementById("ft_list").childNodes;
	var value = "";
	for (i = 0; i < ft_list.length; i++)
	{
		var elem = ft_list[i].childNodes[0].textContent;
		value = value + elem + "||";
	}
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
			var ft_list = document.getElementById("ft_list");
			var div = document.createElement("div");
			div.onclick = function () {
				var newtodo = prompt("Supprimer ? (y/n)");
				if (!!newtodo)
				{
					if (newtodo == "y")
					{
						this.parentNode.removeChild(this);
						create_cookies();
					}
				}
			};
			var newtodo = document.createTextNode(text);
			div.appendChild(newtodo);
			ft_list.insertBefore(div, ft_list.childNodes[0]);
		}
	}
}
