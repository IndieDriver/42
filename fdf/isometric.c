/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:01:44 by amathias          #+#    #+#             */
/*   Updated: 2016/01/09 16:09:39 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_point		setpoint(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

t_point		convertcord(int x, int y)
{
	t_point point;

	point.x = x - y;
	point.y = (x + y) / 2;
	return (point);
}
void		draw_line(t_env env, t_point from, t_point to, t_point tmp)
{
	int dx;
	int dy;
	int error;
	int sx;
	int sy;

	dx = abs(to.x - from.x);
	dy = abs(to.y - from.y);
	sx =  from.x < to.x ? 1 : -1;
	sy = from.y < to.y ? 1 : -1;

	tmp = from;
	if (dx >= dy)
	{
		dy *= 2;
		error = dy - dx;
		dx *= 2;
		while (from.x != to.x)
		{
			mlx_pixel_put(env.mlx, env.win, from.x + (WIDTH/2),
					from.y + (HEIGHT/2), 0x0000FF);
			if (error >= 0)
			{
				from.y += sy;
				error -= dx;
			}
			error += dy;
			from.x += sx;
		}
	}
	else
	{
		dx *= 2;
		error = dx - dy;
		dy *= 2;
		while (from.y != from.y)
		{
			mlx_pixel_put(env.mlx, env.win, from.x + (WIDTH/2),
				from.y + (HEIGHT/2), 0x0000FF);
			if (error >= 0)
			{
				from.x += sx;
				error -= dy;
			}
			error += dx;
			from.y += sy;
		}
	}
	/*
	while (tmp.x <= xend)
	{
		tmp.x++;
		if ((error = error + (dy * 2)) >= 0)
		{
			tmp.y++;
			error = error + ((-dx) * 2);
		}
		mlx_pixel_put(env.mlx, env.win, tmp.x + (WIDTH/2),
				tmp.y + (HEIGHT/2), 0x0000FF);
	} */
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
			printf("i: %d,j: %d\n",i,j);
/*
			draw_line(env, setpoint(0,0), setpoint(0,50), setpoint(0,0));
			draw_line(env, setpoint(0,0), setpoint(50,0), setpoint(0,0));
			draw_line(env, setpoint(0,0), setpoint(50,50), setpoint(0,0));
			draw_line(env, setpoint(0,0), setpoint(0,-50), setpoint(0,0));
			draw_line(env, setpoint(0,0), setpoint(-50,0), setpoint(0,0));
			draw_line(env, setpoint(0,0), setpoint(-50,-50), setpoint(0,0));
*/
			if (i + 1 != row)
			  draw_line(env, grid[i][j], grid[i + 1][j], setpoint(0,0));
			if (j + 1 != col)
			  draw_line(env, grid[i][j], grid[i][j + 1], setpoint(0,0));
			  mlx_pixel_put(env.mlx, env.win, (WIDTH /2) + grid[i][j].x,
			  (HEIGHT / 2) + grid[i][j].y, 0xFF0000);
			from = grid[i][j];
			j++;
		}
		i++;
	}
}

t_point		**init_grid(int grid[4][4], int row, int col, int offset)
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
			//pointgrid[i][j] = tmp;
			pointgrid[i][j] = convertcord(tmp.x,tmp.y);
			j++;
		}
		i++;
	}
	return (pointgrid);
}
