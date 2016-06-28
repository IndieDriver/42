$(document).ready(function(){
	function delete_elem(id) {
		$.ajax({
			type: 'POST',
			url: 'delete.php',
			data: 'id='+id,
		});
	}

	$('#New').click(function(){
		var newtodo = prompt("Nouveau TODO?");
		if (!!newtodo)
		{
			var ft_list = $('#ft_list');
			var div = $('<div>').html(newtodo.toString());
			ft_list.prepend(div);
			insert(newtodo.toString(), div);
		}
	});

	function insert(val, div)
	{
		$.ajax({
			type: 'POST',
			url:'insert.php',
			data:'value='+ val,
			success: function(data) {
				div.attr('id', data);
				div.click(function () {
					var newtodo = prompt("Supprimer ? (y/n)");
					if (!!newtodo)
					{
						if (newtodo == "y")
						{
							$(this).remove();
							delete_elem($(this).attr('id'));
						}
					}
				});
			}
		});
	}
	select();
	function select()
	{
		$.ajax({
			type: 'POST',
			url: 'select.php',
			dataType: 'json',
			success: function (data) {
				$.each(data, function(index, element) {
					var ft_list = $('#ft_list');
					var div = $('<div>').html(element['todo']);
					div.attr('id', element['id']);
					div.click(function () {
						var newtodo = prompt("Supprimer ? (y/n)");
						if (!!newtodo)
						{
							if (newtodo == "y")
							{
								$(this).remove();
								delete_elem($(this).attr('id'));
							}
						}
					});
					ft_list.append(div);
				});
				}
			});
		}
});
