/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <amathias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:44:38 by amathias          #+#    #+#             */
/*   Updated: 2016/02/23 13:28:58 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_hex_color(t_map *map, int x, int y)
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	
	if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1)
		return (0xFFFFFF);
	red = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8];
	green = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 1];
	blue = map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 2];
	return (blue << 16 | green << 8 | red);
}

t_pos	get_pos(int x, int y)
{
	t_pos tmp;

	tmp.x = x;
	tmp.y = y;
	return (tmp);
}

void	draw_pixel_to_image(t_map *map, int x, int y, int color)
{
	unsigned int	color_value;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	if (x < 0 || x > WIDTH - 1|| y < 0 || y > HEIGHT - 1)
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
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			draw_pixel_to_image(map, i, j, color);
			j++;
		}
		i++;
	}
}
