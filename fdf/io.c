/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:43:39 by amathias          #+#    #+#             */
/*   Updated: 2016/02/11 15:43:05 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

int		get_number_of_row(char *file_name)
{
	int		fd;
	char	buf[2];
	int		lnb;

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

t_point	*parse_line(char **line_split, int row, int *col)
{
	t_point	*tmp;
	int		i;

	i = 0;
	while (line_split[i] != 0)
		i++;
	if (!(tmp = (t_point*)malloc(sizeof(t_point) * i)))
		return (NULL);
	i = 0;
	while (line_split[i] != 0)
	{
		tmp[i] = setpoint(i, row, ft_atoi(line_split[i]), 0x0000FF);
		free(line_split[i]);
		i++;
	}
	if (i != *col && *col != 0)
		return (NULL);
	*col = i;
	free(line_split);
	return (tmp);
}

t_point	**read_file(char *file_name, int *row, int *col)
{
	int		fd;
	char	*line;
	t_point	**grid;
	int		i;

	i = 0;
	*row = get_number_of_row(file_name);
	*col = 0;
	if (!(grid = (t_point **)malloc(sizeof(t_point*) * (*row))))
		return (NULL);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(grid[i] = parse_line(ft_strsplit(line, ' '), i, col)))
			return (NULL);
		free(line);
		i++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (grid);
}

t_map	*get_map(char *file_name)
{
	t_map	*map;
	int		height;
	int		width;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	if (!(map->grid = read_file(file_name, &height, &width)))
		return (NULL);
	map->height = height;
	map->width = width;
	return (map);
}
