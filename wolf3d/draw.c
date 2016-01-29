/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:44:38 by amathias          #+#    #+#             */
/*   Updated: 2016/01/29 14:41:59 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_wall_slice(t_map *map, int x, int height)
{
	t_pos to;
	t_pos from;

	to.x = x;
	from.x = x;
	from.y = (HEIGHT / 2) - (height / 2);
	to.y = (HEIGHT / 2) + (height / 2);
	if (from.y < 0 || from.y > HEIGHT)
		from.y = 0;
	if (to.y > HEIGHT || to.y < 0)
		to.y = HEIGHT - 2;
	printf("to.x: %d, to.y: %d, from.x: %d, from.y: %d\n",
			to.x, to.y, from.x, from.y);
	draw_line(map, from, to, 0x0000FF);
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
