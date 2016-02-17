/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <amathias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:44:38 by amathias          #+#    #+#             */
/*   Updated: 2016/02/17 15:38:11 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


int		get_hex_color(t_map *map, int x, int y)
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;

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

void	draw_slice(t_map *map, t_pos from, t_pos to, int color)
{
	while (from.y < to.y)
	{
		draw_pixel_to_image(map, from.x, from.y, color);
		from.y++;
	}
}

void	draw_wall_slice(t_map *map, t_pos pos, int tex_iter)
{
	t_pos to;
	t_pos from;
	t_tex tex;

	tex.id = 1;
	tex.x = tex_iter;
	to.x = pos.x;
	from.x = pos.x;
	from.y = (HEIGHT / 2) - (pos.y / 2);
	to.y = (HEIGHT / 2) + (pos.y / 2);
	if (from.y < 0 || from.y > HEIGHT)
		from.y = 0;
	if (to.y > HEIGHT || to.y < 0)
		to.y = HEIGHT - 1;
	draw_slice(map, get_pos(pos.x, 0), from, 0x00b2ee);
	draw_slice(map, get_pos(pos.x,to.y), get_pos(pos.x, HEIGHT - 1), 0x003547);
	//draw_slice(map, from, to, tex_iter);
	draw_tex(map, from, to, tex);
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
