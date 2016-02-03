/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:19:00 by amathias          #+#    #+#             */
/*   Updated: 2016/02/03 15:47:10 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_color(int i)
{
	int	color;

	color = 256 * 256 * (175 - cos(i)) + 256 * (175 - sin(i)) + (175 - cos(i));
	return (color);
}

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

void	draw_pixel_to_image(t_map *map, int x, int y, int color)
{
	unsigned int	color_value;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

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
