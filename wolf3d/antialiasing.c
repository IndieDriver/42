/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 15:23:15 by amathias          #+#    #+#             */
/*   Updated: 2016/02/22 17:00:56 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_average(t_map *map, int color1, int color2)
{
	unsigned int color_value1;
	unsigned int color_value2;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	
	color_value1 = mlx_get_color_value(map->env.mlx, color1);
	color_value2 = mlx_get_color_value(map->env.mlx, color2);
	red = (((color1 & 0xFF0000) >> 16) +
			((color2 & 0xFF0000) >> 16)) / 2;
	green = (((color1 & 0xFF00) >> 8) +
			((color2 & 0xFF00) >> 8)) / 2;
	blue = (((color1 & 0xFF)) +
			((color2 & 0xFF))) / 2;
	return (red << 16 | green << 8 | blue);	
}

int		get_average_fourway(t_map *map, t_pos pos, int color)
{
	int c1;
	int c2;
	int c3;
	int c4;

	(void)color;
	c1 = get_average(map, get_hex_color(map, pos.x, pos.y),
			get_hex_color(map, pos.x - 1, pos.y));
	/*c2 = get_average(map, get_hex_color(map, pos.x, pos.y),
			get_hex_color(map, pos.x + 1, pos.y)); */
	c3 = get_average(map, get_hex_color(map, pos.x, pos.y),
			get_hex_color(map, pos.x, pos.y - 1));
	c4 = get_average(map, get_hex_color(map, pos.x, pos.y),
			get_hex_color(map, pos.x, pos.y + 1));
	c1 = get_average(map, c1, color);
	c2 = get_average(map, c3, c4);
	return (get_average(map, c1, c2));

}

void	anti_aliasing(t_map *map, t_pos pos, int color, int side)
{
	int sy;
	int c;

	sy = side == 1 ? 1 : -1;
	c = get_hex_color(map, pos.x, pos.y + sy);
	//pos.y -= sy;
	//printf("m: %#08x| c: %#08x| color: %#08x\n",get_average(map,c, color),c,color);
	//draw_pixel_to_image(map, pos.x, pos.y - sy, get_average(map, c, color));
	c = get_average_fourway(map, get_pos(pos.x, pos.y + 2 * sy), color);	
	draw_pixel_to_image(map, pos.x, pos.y + 2 * sy, get_average(map, c, color));
	c = get_average_fourway(map, get_pos(pos.x, pos.y + sy), color);	
	draw_pixel_to_image(map, pos.x, pos.y + sy, get_average(map, c, color));
	c = get_average_fourway(map, pos, color);
	draw_pixel_to_image(map, pos.x, pos.y, get_average(map, c, color));


}
