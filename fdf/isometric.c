/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 15:01:44 by amathias          #+#    #+#             */
/*   Updated: 2016/01/08 16:28:56 by amathias         ###   ########.fr       */
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
	
	from = convertcord(from.x, from.y);
	to = convertcord(to.x, to.y);
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

void		draw_iso(t_env env, int grid[4][4], int row, int col)
{
	int i;
	int j;
	t_point point;
	t_point from;
	t_point to;

	i = 0;
	while (i < row)
	{
		j = 0;
		from = setpoint(i*50 - grid[i][j], j*50 - grid[i][j]);
		while (j < col)
		{
			point = convertcord(i*50 - grid[i][j],j*50 - grid[i][j]);
			to = setpoint(i*50 - grid[i][j], j*50 - grid[i][j]);
			draw_line(env, from, to, setpoint(0,0));
			mlx_pixel_put(env.mlx, env.win, (WIDTH /2) + point.x,
					(HEIGHT / 2) + point.y, 0xFF0000);
			from = to;
			j++;
		}
		i++;
	}
}
