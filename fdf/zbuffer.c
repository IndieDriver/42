/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:46:57 by amathias          #+#    #+#             */
/*   Updated: 2016/01/31 16:34:50 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_polygon(t_map *map)
{
	t_point point;

	point = get_point(map);
	//if (point.x != 0)
	fill_rect(map, point.x, point.y, 0xFFFFFF);
}

void	replace_color(t_map *map, color;)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			//replace color 
			x++;
		}
		y++:
	}
}
t_point	get_point(t_map *map)
{
	int y;
	int x;
	int line;
	t_point point;

	line = 0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		line = 0;
		point.x = -1;
		while (x < WIDTH)
		{
			if (get_hex_color(map, x, y) == 0x0000FF && line == 0 && point.x == -1)
				line++;
			if (get_hex_color(map, x, y) == 0x0000FF && point.x != -1)
				line++;
			if (line == 1 && get_hex_color(map, x, y) != 0x0000FF
					&& point.x == -1)
			{
				point.x = x;
				point.y = y;
			}
			if (line == 2 && point.x != -1)
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
