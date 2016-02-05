/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:44:38 by amathias          #+#    #+#             */
/*   Updated: 2016/02/05 14:02:08 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pos	get_pos(int x, int y)
{
	t_pos tmp;
	
	tmp.x = x;
	tmp.y = y;
	return (tmp);
}
void	draw_slice(t_map *map, t_pos from, t_pos to, int tex_iter)
{
	int i;
	int j;

	i = from.y;
	j = 0;
	while (i < to.y && j < 64)
	{
		printf("tex\n");
		draw_pixel_to_image(map, from.x, i, map->tex[j][tex_iter]);
		i++;
		j++;
	}
}

void	draw_wall_slice(t_map *map, t_pos pos, int tex_iter)
{
	t_pos to;
	t_pos from;

	to.x = pos.x;
	from.x = pos.x;
	from.y = (HEIGHT / 2) - (pos.y / 2);
	to.y = (HEIGHT / 2) + (pos.y / 2);
	if (from.y < 0 || from.y > HEIGHT)
		from.y = 0;
	if (to.y > HEIGHT || to.y < 0)
		to.y = HEIGHT - 1;
	draw_line(map, get_pos(pos.x, 0), from, 0x00b2ee);
	draw_line(map, get_pos(pos.x,to.y), get_pos(pos.x, HEIGHT - 1), 0x003547);
	draw_slice(map, from, to, tex_iter);
}

void	draw_pixel_to_image(t_map *map, int x, int y, int color)
{
	unsigned int	color_value;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
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
