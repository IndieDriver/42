/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:45:56 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 15:15:14 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_parse_error(int type, int line)
{
	ft_putstr("Parse error on line: ");
	ft_putnbr(line);
	ft_putstr(" | type: ");
	if (type == 1)
		ft_putstr("malloc error\n");
	if (type == 2)
		ft_putstr("invalid file\n");
	if (type == 3)
		ft_putstr("vector need 3 args (e.g: pos: 0.0 0.0 0.0)\n");
	if (type == 4)
		ft_putstr("screen need 2 args (e.g: screen: 720 480)\n");
	if (type == 5)
		ft_putstr("invalid number of args\n");
	if (type == 6)
		ft_putstr("invalid color format (e.g: rgb: 0xFF0000)\n");
	exit(0);
}

int		get_row_nb(char *file_name)
{
	char	buf[2];
	int		lnb;
	int		fd;

	lnb = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (-1);
	while (read(fd, &buf, 1))
	{
		if (buf[0] == '\n')
			lnb++;
	}
	if (close(fd) == -1)
		return (-1);
	return (lnb);
}

char	**get_file(char *file_name)
{
	char	**file;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (!(file = (char**)malloc(sizeof(char*) * get_row_nb(file_name) + 1)))
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		file[i] = line;
		i++;
	}
	file[i] = NULL;
	if (close(fd) == -1)
		return (NULL);
	return (file);
}

void	parse_file(t_map *map, char *file_name)
{
	char	**file;
	t_scene	scene;
	int		i;

	i = 0;
	file = get_file(file_name);
	while (file[i] != NULL)
	{
		if (contain(file[i], "scene:"))
			get_scene(file, &scene, i);
		if (contain(file[i], "object:"))
			get_object(file, &scene, i);
		i++;
	}
	map->scene = scene;
}
