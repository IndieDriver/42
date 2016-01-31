/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:19:00 by amathias          #+#    #+#             */
/*   Updated: 2016/01/31 16:34:52 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_hex_color(t_map *map, int x, int y)
{
	t_rgb rgb;
	
	rgb.red = map->img.data[y * map->img.size_line +
		(x * map->img.bpp) / 8];
	rgb.green = map->img.data[y * map->img.size_line +
		(x * map->img.bpp) / 8 + 1];
	rgb.blue = map->img.data[y * map->img.size_line +
		(x * map->img.bpp) / 8 + 2];
	return (rgb.blue << 16 | rgb.green << 8 | rgb.red);
}

void	fill_rect(t_map *map, int x, int y, int color)
{
	if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1)
		return ;
	if (get_hex_color(map, x, y) != 0x0000FF
			&& get_hex_color(map, x, y) != color)
	{
		draw_pixel_to_image(map, x, y, color);
		//mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0,0);
		fill_rect(map, x + 1, y, color);
		fill_rect(map, x, y + 1, color);
		fill_rect(map, x - 1, y, color);
		fill_rect(map, x, y - 1, color);
	}
}


void	draw_pixel_to_image(t_map *map, int x, int y, int color)
{
	unsigned int	color_value;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	//printf("x: %d| y: %d| color: %#08x\n",x,y,color);
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	color_value = mlx_get_color_value(map->env.mlx, color);
	red = (color_value & 0xFF0000) >> 16;
	green = (color_value & 0xFF00) >> 8;
	blue = (color_value & 0xFF);
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8] = blue;
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 1] = green;
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 2] = red;
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
