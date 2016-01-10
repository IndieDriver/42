/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:01:44 by amathias          #+#    #+#             */
/*   Updated: 2016/01/10 16:41:47 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point		setpoint(int x, int y, int z, char color[10])
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	ft_strcpy(point.color,color);
	return (point);
}

t_point		convertcord(int x, int y)
{
	t_point point;

	/*point.x = x - y;
	point.y = (x + y) / 2;*/
	point.x = (x * cos(45)) - (y * sin(45));
	point.y = (x * sin(45)) + (y * cos(45));
	return (point);
}

void		draw_iso(t_env env, t_point **grid, int row, int col)
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
				draw_line(env, grid[i][j], grid[i + 1][j]);
			if (j + 1 != col)
				draw_line(env, grid[i][j], grid[i][j + 1]);
			mlx_pixel_put(env.mlx, env.win, (WIDTH /2) + grid[i][j].x,(HEIGHT / 2) + grid[i][j].y, 0xFF0000);
			from = grid[i][j];
			j++;
		}
		i++;
	}
}
/*
t_point		**init_grid(int grid[11][19], int row, int col, int offset)
{
	int i;
	int j;
	t_point **pointgrid;
	t_point tmp;	

	i = 0;
	if (!(pointgrid = (t_point **)malloc(sizeof(t_point*) * row)))
		return (NULL);
	while (i < row)
	{
		if (!(pointgrid[i] = (t_point*)malloc(sizeof(t_point) * col)))
			return (NULL);
		j = 0;
		while (j < col)
		{
			tmp = setpoint(i*offset - grid[i][j],
					j*offset - grid[i][j]);
			pointgrid[i][j] = convertcord(tmp.x,tmp.y);
			j++;
		}
		i++;
	}
	return (pointgrid);
} */
