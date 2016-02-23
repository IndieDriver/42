/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:45:56 by amathias          #+#    #+#             */
/*   Updated: 2016/02/23 16:45:06 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_object(int fd)
{
	(void)fd;
}

t_vec	process_scene(char **line_split, int type)
{
	t_vec vec;
	int i;

	if (type == 1)
	{
		vec.x = ft_atoi_double(line_split[0]);
		vec.y = ft_atoi_double(line_split[1]);
		vec.z = ft_atoi_double(line_split[2]);
		vec.dir = ft_atoi_double(line_split[3]);
	}
	else
	{
		
	}
	i = 0;
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
	return (vec);
}

t_scene	get_scene(int fd)
{
	t_scene scene;
	char *line;

	while (get_next_line(fd, &line) == 1)
	{
		if (contain(line, "camera:"))
			scene.pos = process_scene(ft_strsplit(ft_strchr(line, ':') + 1, ' '));
		if (contain(line, "screen:"))
			scene.pos
		free(line);
	}

	printf("camera| x: %f| y: %f| z: %f| dir: %f\n",scene.pos.x,
			scene.pos.y, scene.pos.z, scene.pos.dir);
	return (scene);
}

void	parse_file(t_map *map, char *file_name)
{
	char *line;
	int fd;

	(void)map;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return ;
	while (get_next_line(fd, &line) == 1)
	{
		if (contain(line, "scene:"))
			map->scene = get_scene(fd);
		if (contain(line, "object:"))
			get_object(fd);
	}
}
