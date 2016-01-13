/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:19:00 by amathias          #+#    #+#             */
/*   Updated: 2016/01/13 15:13:47 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_rgb_equal(t_rgb color1, t_rgb color2)
{
	/*printf("color1: red %x green %x blue %x\ncolor2: red %x green %x blue %x\n",
		color1.red, color1.green, color1.blue, color2.red, color2.green, color2.blue); */
	if (color1.red != color2.red)
		return (0);
	if (color1.green != color2.green)
		return (0);
	if (color1.blue != color2.blue)
		return (0);
	//printf("return (1)\n");
	return (1);
}

t_rgb	convert_to_rgb(t_map *map, int color)
{
	unsigned int color_value;
	t_rgb rgb;

	color_value = mlx_get_color_value(map->env.mlx, color);
	rgb.red = (color_value & 0xFF0000) >> 16;
	rgb.green = (color_value & 0xFF00) >> 8;
	rgb.blue = (color_value & 0xFF);
	return (rgb);
}

t_rgb	get_pixel_color(t_map *map, int x, int y)
{
	t_rgb rgb;
	
	rgb.red = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8];
	rgb.green = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 1];
	rgb.blue = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 2];
	return (rgb);
}

void	fill_rect(t_map *map, int x,int y,int color)
{
	/*printf("x: %d, y: %d color: %#08x,get_pixel_color: %#08x, unsigned color: %#08x,unsigned get_pixelcolor: %#08x\n",x,y,color,
	get_pixel_color(map,x,y),mlx_get_color_value(map->env.mlx, color),
	mlx_get_color_value(map->env.mlx, get_pixel_color(map, x, y))); */
	//if	(is_rgb_equal(get_pixel_color(map, x, y), convert_to_rgb(map, color)))
		//return ;
	//printf("get_pixel_color = color\n");
	printf("x: %d, y: %d\n",x, y);

	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return ;
	//printf("in map\n");
	if (!is_rgb_equal(get_pixel_color(map, x, y), convert_to_rgb(map, 0x0000FF))
		&& !is_rgb_equal(get_pixel_color(map, x, y), convert_to_rgb(map,color)))
	{
		//printf("draw_pixel\n");
		draw_pixel_to_image(map, x, y, color);
		mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0,0);
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
