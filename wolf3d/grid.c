/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:34:17 by amathias          #+#    #+#             */
/*   Updated: 2016/02/22 14:54:54 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_number_of_row(char *file_name)
{
	int fd;
	char buf[2];
	int lnb;
	
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

static int	*get_line(t_map *map, char **line_split)
{
	int *line;
	int i;

	i = 0;
	while (line_split[i] != 0)
		i++;
	if (!(line = (int*)malloc(sizeof(int) * i)))
		return (NULL);
	i = 0;
	while (line_split[i] != 0)
	{
		line[i] = ft_atoi(line_split[i]);
		free(line_split[i]);
		i++;
	}
	map->width = i;
	free(line_split);
	return (line);
}

int		**get_grid(t_map *map, char *file_name)
{
	int **grid;
	char *line;
	int fd;
	int i;
	
	i = 0;
	map->height = get_number_of_row(file_name);
	if (!(grid = (int**)malloc(sizeof(int*) * map->height)))
		return (NULL);
	if (!(fd = open(file_name, O_RDONLY)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		grid[i] = get_line(map, ft_strsplit(line, ' '));
		free(line);
		i++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (grid);
}
