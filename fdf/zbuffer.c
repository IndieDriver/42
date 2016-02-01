/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:46:57 by amathias          #+#    #+#             */
/*   Updated: 2016/02/01 11:59:49 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	replace_color(t_map *map, int color)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (get_hex_color(map, j, i) == 0xFFFFFF)
				draw_pixel_to_image(map, j, i, color);
			j++;
		}
		i++;
	}
}

void	fill_polygon(t_map *map)
{
	t_point point;

	point = get_point(map);
	fill_rect(map, point.x, point.y, 0xFFFFFF);
	replace_color(map, 0x000000);
	printf("fill_polygon\n");
}

t_point	get_point(t_map *map)
{
	int y;
	int x;
	int l;
	int first;
	t_point point;

	l = 0;
	y = 0;
	first = 0;
	while (y < HEIGHT)
	{
		x = 0;
		l = 0;
		point.x = -1;
		while (x < WIDTH)
		{
			if (get_hex_color(map, x, y) == 0x0000FF && first < 10)
			{
				first++;
				break ;
			}
			if (get_hex_color(map, x, y) == 0x0000FF && l == 0 && point.x == -1)
				l++;
			if (get_hex_color(map, x, y) == 0x0000FF && point.x != -1)
				l++;
			if (l == 1 && get_hex_color(map, x, y) != 0x0000FF
					&& point.x == -1)
			{
				point.x = x;
				point.y = y;
			}
			if (l == 2 && point.x != -1)
			{
				draw_pixel_to_image(map, point.x, point.y, 0xFFFF00);
				return (point);
			}
			x++;
		}
		y++;
	}
	printf("line not found\n");
	return (setpoint(0,0,0,0x0000FF));
}
