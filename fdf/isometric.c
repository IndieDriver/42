/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:01:44 by amathias          #+#    #+#             */
/*   Updated: 2016/01/09 10:37:43 by amathias         ###   ########.fr       */
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
	int p;
	int xend;

	printf("from.x: %d, from.y: %d\nto.x: %d, to.y: %d\n",from.x,from.y,to.x,to.y);	
	dx = abs(to.x - from.x);
	dy = abs(to.y - from.y);
	p = 2 * (dx - dy);
	xend = from.x > to.x ? from.x : to.x;
	if (from.x > to.x)
		tmp = setpoint(to.x, to.y);
	else
		tmp = setpoint(from.x, from.y);
	while (tmp.x <= xend)
	{
		tmp.x++;
		if (p < 0)
			p = p + 2 * (dy);
		else
		{
			tmp.y++;
			p = p + (2 * dy) - (2 * dx);
		}
		mlx_pixel_put(env.mlx, env.win, tmp.x + (WIDTH/2),
				tmp.y + (HEIGHT/2), 0x0000FF);
	}
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
			draw_line(env, setpoint(0,0), setpoint(0,50), setpoint(0,0));
			draw_line(env, setpoint(0,0), setpoint(50,50), setpoint(0,0));
			draw_line(env, setpoint(0,0), setpoint(50,0), setpoint(0,0));
			draw_line(env, setpoint(0,0), setpoint(50,50), setpoint(0,0));
			/*
			if (i + 1 != row)
				draw_line(env, from, grid[i + 1][j], setpoint(0,0));
			if (j + 1 != col)
				draw_line(env, from, grid[i][j + 1], setpoint(0,0)); 
			mlx_pixel_put(env.mlx, env.win, (WIDTH /2) + grid[i][j].x,
					(HEIGHT / 2) + grid[i][j].y, 0xFF0000); */
			from = to;
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
