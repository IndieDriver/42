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

int		get_min(t_rect rect)
{
	if (rect.tl.y < rect.tr.y && rect.tl.y < rect.br.y && rect.tl.y < rect.bl.y)
		return (rect.tl.y);
	if (rect.tr.y < rect.tl.y && rect.tr.y < rect.br.y && rect.tr.y < rect.bl.y)
		return (rect.tr.y);
	if (rect.br.y < rect.tr.y && rect.br.y < rect.tl.y && rect.br.y < rect.bl.y)
		return (rect.br.y);
	if (rect.bl.y < rect.tl.y && rect.bl.y < rect.tr.y && rect.bl.y < rect.br.y)
		return (rect.bl.y);
	printf("fail\n");
	return (-1);
}

int		get_max(t_rect rect)
{
	if (rect.tl.y > rect.tr.y && rect.tl.y > rect.br.y && rect.tl.y > rect.bl.y)
		return (rect.tl.y);
	if (rect.tr.y > rect.tl.y && rect.tr.y > rect.br.y && rect.tr.y > rect.bl.y)
		return (rect.tr.y);
	if (rect.br.y > rect.tr.y && rect.br.y > rect.tl.y && rect.br.y > rect.bl.y)
		return (rect.br.y);
	if (rect.bl.y > rect.tl.y && rect.bl.y > rect.tr.y && rect.bl.y > rect.br.y)
		return (rect.bl.y);
	printf("fail\n");
	return (-1);
}

t_point	get_point(t_map *map, t_rect rect)
{
	int ymin;
	int ymax;
	int x;
	int line;
	t_point point;

	line = 0;
	ymin = get_min(rect);
	ymin = 0;
	ymax = get_max(rect);
	ymax = HEIGHT;
	while (ymin < ymax)
	{
		x = 0;
		line = 0;
		point.x = -1;
		while (x < WIDTH)
		{
			if (get_hex_color(map, x, ymin) == 0x0000FF)
			{
				line++;
			}
			if (line == 1 && get_hex_color(map, x, ymin) != 0x0000FF
					&& point.x == -1)
			{
				point.x = x;
				point.y = ymin;
			}
			if (line == 2 && point.x != -1)
			{
				draw_pixel_to_image(map, point.x, point.y, 0xFFFF00);
				return (point);
			}
			x++;
		}
		ymin++;
	}
	printf("line not found\n");
	return (setpoint(0,0,0,0x0000FF));
}
