/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:19:00 by amathias          #+#    #+#             */
/*   Updated: 2016/01/12 15:55:11 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_pixel_color(t_map *map, int x, int y)
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	
	red = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8];
	green = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 1];
	blue = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 2];
	return ((red << 16) + (green << 8) + blue);
}

void	fill_rect(t_map *map, int x,int y,int color)
{
	//printf("x: %d, y: %d color: %#08x,get_pixel_color: %#08x\n",x,y,color,
	printf("x: %d, y: %d color: %d,get_pixel_color: %d\n",x,y,color,
	get_pixel_color(map,x,y));
	if (get_pixel_color(map, x, y) == color)
		return ;
	printf("get_pixel_color = color\n");
	if (color != 0x0000ff || color != 0xff0000)
		return ;
	printf("draw_pixel\n");
	draw_pixel_to_image(map, x, y, color);
	fill_rect(map, x, y + 1, color);
	fill_rect(map, x, y - 1, color);
	fill_rect(map, x - 1, y, color);
	fill_rect(map, x + 1, y, color);
	return ;
}


void	draw_pixel_to_image(t_map *map, int x, int y, int color)
{
	unsigned int	color_value;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	color_value = mlx_get_color_value(map->env.mlx, color);
	red = (color_value & 0xFF0000) >> 16;
	green = (color_value & 0xFF00) >> 8;
	blue = (color_value & 0xFF);
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8] = red;
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 1] = green;
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 2] = blue;
}

void	init_image(t_map *map, int color)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			draw_pixel_to_image(map, j, i, color);
			j++;
		}
		i++;
	}
}
