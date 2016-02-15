/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 11:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/02/15 11:51:39 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_pixel_to_mmap(t_map *map, int x, int y, int color)
{
	unsigned int color_value;
	unsigned char	red;
	unsigned char 	blue;
	unsigned char	green;
	
	if (x < 0 || y < 0 || x > 99 || y > 99)
		return ;	
	color_value = mlx_get_color_value(map->env.mlx, color);
	red = (color_value & 0xFF0000) >> 16;
	green = (color_value & 0xFF00) >> 8;
	blue = (color_value & 0xFF);
	map->mmap.data[y * map->mmap.size_line + (x * map->mmap.bpp) / 8] = blue;
	map->mmap.data[y * map->mmap.size_line + (x * map->mmap.bpp) / 8 + 1] =
		green;
	map->mmap.data[y * map->mmap.size_line + (x * map->mmap.bpp) / 8 + 2] = red;
}

void	init_mmap(t_map *map)
{
	int i;
	int j;
	int color;

	i = 0;

	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			color = get_hex_color(map, (WIDTH - 125) + j, (HEIGHT - 125) + i);
			draw_pixel_to_mmap(map, j, i, color / 2);
			j++;
		}
		i++;
	}
}

void	init_pos(t_map *map, t_pos *start, t_pos *end)
{
	int x;
	int y;

	x = (int)floor(map->pos.x);
	y = (int)floor(map->pos.y);
	start->x = x - 5 > 0 ? x - 5 : 0;
	end->x = x + 5 < map->width ? x + 5 : map->width;
	start->y = y - 5 > 0 ? y - 5 : 0;
	end->y = y + 5 < map->height ? y + 5 : map->height;
}

void	draw_square(t_map *map, int x, int y, int color)
{
	int i;
	int j;

	i = y + 10;
	j = x + 10;
	while (y < i)
	{
		x = j - 10;
		while (x < j)
		{
			draw_pixel_to_mmap(map, x, y, color);
			x++;
		}
		y++;
	}
}

void	print_map(t_map *map)
{
	int tmp;
	int color;
	int i;
	int j;
	t_pos start;
	t_pos end;

	init_pos(map, &start, &end);
	j = 10 - (end.y - start.y);
	j = end.y == map->width ? 0 : 10 - (end.y - start.y);
	while (start.y < end.y)
	{
		tmp = start.x;
		i = 10 - (end.x - tmp);
		i = end.x == map->height ? 0 : 10 - (end.x - start.x);
		while (tmp < end.x)
		{
			color = map->grid[tmp][start.y] == 0 ? 0x010101 : 0xFF0000;
			if (map->grid[tmp][start.y] != 0)
				draw_square(map, (j * 10) - (fmod(map->pos.y, 1) * 10 ),
						(i * 10) - (fmod(map->pos.x, 1) * 10), color);
			tmp++;
			i++;
		}
		start.y++;
		j++;
	}
}

void	draw_mmap(t_map *map)
{
	map->mmap.img = mlx_new_image(map->env.mlx, 100, 100);
	map->mmap.data = mlx_get_data_addr(map->mmap.img, &(map->mmap.bpp),
			&(map->mmap.size_line), &(map->mmap.endian));
	init_mmap(map);
	print_map(map);
	draw_pixel_to_mmap(map, 49, 50, 0x00FF00);
	draw_pixel_to_mmap(map, 51, 50, 0x00FF00);
	draw_pixel_to_mmap(map, 50, 49, 0x00FF00);
	draw_pixel_to_mmap(map, 50, 51, 0x00FF00);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->mmap.img,
			WIDTH - 125, HEIGHT - 125);
	mlx_destroy_image(map->env.mlx, map->mmap.img);
}


