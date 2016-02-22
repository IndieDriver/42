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

int		get_average(t_map *map, int color1, int color2, int weight)
{
	unsigned int color_value1;
	unsigned int color_value2;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	
	color_value1 = mlx_get_color_value(map->env.mlx, color1);
	color_value2 = mlx_get_color_value(map->env.mlx, color2);
	if (weight > 15)
		weight = 4;
	if (weight > 10)
		weight = 3;
	if (weight > 5)
		weight = 2;
	else
		weight = 1;
	red = ((((color1 & 0xFF0000) >> 16)) +
			((color2 & 0xFF0000) >> 16)) / 2 + weight;
	green = ((((color1 & 0xFF00) >> 8) * weight) +
			((color2 & 0xFF00) >> 8)) / 2 + weight;
	blue = (((color1 & 0xFF) * weight) +
			((color2 & 0xFF))) / 2 + weight;
	return (red << 16 | green << 8 | blue);	
}
/*
int		get_average_fourway(t_map *map, t_pos pos, int color)
{
	int c1;
	int c2;
	int c3;
	int c4;

	c1 = get_average(map, get_hex_color(map, pos.x, pos.y),
			get_hex_color(map, pos.x - 1, pos.y));
	c2 = get_average(map, get_hex_color(map, pos.x, pos.y),
			get_hex_color(map, pos.x + 1, pos.y));
	c3 = get_average(map, get_hex_color(map, pos.x, pos.y),
			get_hex_color(map, pos.x, pos.y - 1));
	c4 = get_average(map, get_hex_color(map, pos.x, pos.y),
			get_hex_color(map, pos.x, pos.y + 1));
	c1 = get_average(map, c1, color);
	c2 = get_average(map, c2, color);
	return (get_average(map, c1, color));

} */
void	apply_aa(t_map *map, t_pos pos, int color)
{
	/*draw_pixel_to_image(map, pos.x, pos.y, 
	 get_average_fourway(map, pos, 0x00b2ee));
	draw_pixel_to_image(map, pos.x, pos.y + 1,  
	 get_average_fourway(map, pos, 0x00b2ee));
	draw_pixel_to_image(map, pos.x, pos.y - 1,  
	 get_average_fourway(map, pos, 0x00b2ee)); */

	int i;

	i = pos.x;
	while (get_hex_color(map, i, pos.y) == color)
		i++;
	draw_pixel_to_image(map, pos.x, pos.y,
		get_average(map, i * color,get_hex_color(map, pos.x, pos.y), i));

}

void	anti_aliasing(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			//printf("hex_color: %#08x\n",get_hex_color(map, i, j));
			if (get_hex_color(map, i, j) != 0x00b2ee)
			{
				if (j == 0)
					break ;
				apply_aa(map, get_pos(i, j), 0x00b2ee);
				break;
			}
			j++;
		}
		i++;
	}
}
