/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:01:44 by amathias          #+#    #+#             */
/*   Updated: 2016/01/12 16:34:02 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point		setpoint(int x, int y, int z, int color)
{
	t_point point;

	point.x = x - (z);
	point.y = y - (z);
	point.z = z;
	point.color = color;
	return (point);
}

t_point		convertcord(t_point point)
{
	t_point tmp;

	tmp = setpoint(point.x, point.y, point.z, point.color);
	tmp.x = point.x - point.y;
	tmp.y = (point.x + point.y) / 2;
	return (tmp);
}

void		draw_iso(t_map *map, t_point **grid, int row, int col)
{
	int i;
	int j;
	t_point from;
	t_point to;

	i = 0;
	while (i < row)
	{
		j = 0;
		from = grid[i][j];
		while (j < col)
		{
			to = grid[i][j];
			if (i + 1 != row)
				draw_line(map, grid[i][j], grid[i + 1][j]);
			if (j + 1 != col)
				draw_line(map, grid[i][j], grid[i][j + 1]);
			if (j + 1 != col && i + 1 != row)
			{
				draw_line(map, grid[i + 1][j], grid[i + 1][j + 1]);
				draw_line(map, grid[i][j + 1], grid[i + 1][j + 1]);
				fill_rect(map, (grid[i][j].x + 1) + (WIDTH / 2),
				(grid[i][j].y + 1) + (HEIGHT / 2), 0x0000FF);
			}
			from = grid[i][j];
			j++;
		}
		i++;
	}
}

int		is_cord_valid(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j].x + (WIDTH / 2) >= WIDTH
					|| map->grid[i][j].x + (WIDTH / 2) <= 0
					|| map->grid[i][j].y + (HEIGHT / 2) <= 0
					|| map->grid[i][j].y + (HEIGHT / 2) >= HEIGHT)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_map	*adapt_grid(t_map *map)
{
	int i;
	int j;

	while (!is_cord_valid(map))
	{
		i = 0;
		while (i < map->height)
		{
			j = 0;
			while (j < map->width)
			{
				map->grid[i][j].x /= 2;
				map->grid[i][j].y /= 2;
				j++;
			}
			i++;
		}
	}
	return (map);
}
