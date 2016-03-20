/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <amathias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 13:44:38 by amathias          #+#    #+#             */
/*   Updated: 2016/03/20 15:15:14 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

void	draw_slice(t_map *map, t_pos from, t_pos to, int color)
{
	from.y = from.y < 0 ? 0 : from.y;
	to.y = to.y > HEIGHT ? HEIGHT : to.y;
	while (from.y < to.y)
	{
		draw_pixel_to_image(map, from.x, from.y, color);
		from.y++;
	}
}

void	draw_wall_slice(t_map *map, t_pos pos, t_tex tex)
{
	t_pos to;
	t_pos from;

	to.x = pos.x;
	from.x = pos.x;
	from.y = (HEIGHT / 2) - (pos.y / 2);
	to.y = (HEIGHT / 2) + (pos.y / 2);
	draw_slice(map, get_pos(pos.x, 0), from, 0x00b2ee);
	draw_slice(map, get_pos(pos.x, to.y), get_pos(pos.x, HEIGHT - 1), 0x003547);
	draw_tex(map, from, to, tex);
}

void	draw_pixel_to_image(t_map *map, int x, int y, int color)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1)
		return ;
	red = (color & 0xFF0000) >> 16;
	green = (color & 0xFF00) >> 8;
	blue = (color & 0xFF);
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8] = blue;
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 1] = green;
	map->img.data[y * map->img.size_line + (x * map->img.bpp) / 8 + 2] = red;
}
