/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:02:49 by amathias          #+#    #+#             */
/*   Updated: 2016/01/12 16:17:23 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	convert_octan(int *dx, int *dy, int *sx, int *sy)
{
	*sx = *dx > 0 ? 1 : -1;
	*sy = *dy > 0 ? 1 : -1;
	*dx = *dx > 0 ? *dx : -(*dx);
	*dy = *dy > 0 ? *dy : -(*dy);
}

void	bresenham(t_map *map, t_point from, t_point to, t_line value)
{
	value.err = 2 * (value.dy - value.dx);
	while ((from.x <= to.x && value.sx == 1)
			|| (from.x >= to.x && value.sx == -1))
	{
		draw_pixel_to_image(map, from.x + (WIDTH / 2),
				from.y + (HEIGHT / 2), from.color);
		if (value.err >= 0)
		{
			from.y += value.sy;
			value.err += 2 * (value.dy - value.dx);
		}
		else
			value.err += 2 * (value.dy);
		from.x += value.sx;
	}
}

void	bresenham_inverse(t_map *map, t_point from, t_point to, t_line value)
{
	value.err = 2 * (value.dx - value.dy);
	while ((from.y <= to.y && value.sy == 1)
			|| (from.y >= to.y && value.sy == -1))
	{
		draw_pixel_to_image(map, from.x + (WIDTH/2),
			from.y + (HEIGHT/2), from.color);
		if (value.err >= 0)
		{
			from.x += value.sx;
			value.err += 2 * (value.dx - value.dy);
		}
		else
			value.err += 2 * value.dx;
		from.y += value.sy;
	}
}

void	draw_line(t_map *map, t_point from, t_point to)
{
	t_line value;

	value.dx = to.x - from.x;
	value.dy = to.y - from.y;
	convert_octan(&value.dx, &value.dy, &value.sx, &value.sy);
	if (value.dx > value.dy)
		bresenham(map, from, to, value);
	else
		bresenham_inverse(map, from, to, value);
}
