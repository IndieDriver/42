/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:01:44 by amathias          #+#    #+#             */
/*   Updated: 2016/02/12 09:39:56 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_point	setpoint(int x, int y, int z, int color)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}

t_point	convertcord(t_point point)
{
	t_point tmp;

	tmp = setpoint(point.x, point.y, point.z, point.color);
	tmp.x = point.x - point.y;
	tmp.y = (point.x + point.y) / 2;
	return (tmp);
}

void	draw_iso(t_map *map, t_point **grid, int row, int col)
{
	int i;
	int j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (i + 1 != row)
				draw_line(map, grid[i][j], grid[i + 1][j], grid[i][j].color);
			if (j + 1 != col)
				draw_line(map, grid[i][j], grid[i][j + 1], grid[i][j].color);
			j++;
		}
		i++;
	}
}
