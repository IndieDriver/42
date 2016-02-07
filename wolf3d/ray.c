/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:40:41 by amathias          #+#    #+#             */
/*   Updated: 2016/02/07 14:58:30 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_dda	init_dda(t_pos pos, t_vec delta, t_vec raypos, t_vec raydir)
{
	t_dda value;

	if (raydir.x < 0)
	{
		value.sx = -1.0;
		value.dx = (raypos.x - (double)pos.x) * delta.x;
	}
	else
	{
		value.sx = 1.0;
		value.dx = ((double)pos.x + 1.0 - raypos.x) * delta.x;
	}
	if (raydir.y < 0)
	{
		value.sy = -1.0;
		value.dy = (raypos.y - (double)pos.y) * delta.y;
	}
	else
	{
		value.sy = 1.0;
		value.dy = ((double)pos.y + 1.0 - raypos.y) * delta.y;
	}
	return (value);
}

int		get_tex_iter(t_dda value, t_vec raydir, t_pos pos, t_vec raypos)
{
	t_tex	tex;

	//printf("value.dx: %f\n", value.dx);
	if (value.side == 1)
		tex.wallcord = raypos.x + ((pos.y - raypos.y +
				(1 - value.sy) / 2) / raydir.y) * raydir.x;
	else
		tex.wallcord = raypos.y + ((pos.x - raypos.x +
				(1 - value.sx) / 2) / raydir.x) * raydir.y;
	printf("tex.wallcord: %f\n", tex.wallcord);
	tex.wallcord -= floor(tex.wallcord);
	tex.x = (int)(tex.wallcord * 64.0);
	if (value.side == 0 && raydir.x > 0)
		tex.x = 64 - tex.x - 1;
	if (value.side == 1 && raydir.y < 0)
		tex.x = 64 - tex.x - 1;
	//printf("tex_iter: %f\n", tex_iter);
	/*if (value.side == 1 && raydir.y < 0)
		tex_iter = 64 - tex_iter;
	else if (value.side == 0 && raydir.x > 0)
		tex_iter = 64 - tex_iter; */
	/*else if (value.side == 0 && value.sx < 0)
		//tex_iter = 1.0 - fmod(value.dx, 1);
	else if (value.side == 1 && value.sy > 0)
		//tex_iter = fmod(value.dy, 1);
	else if (value.side == 1 && value.sy < 0)
		//tex_iter = 1.0 - fmod(value.dy, 1); */
	printf("tex3: %d\n", tex.x);
	return (tex.x);
}

double	dda(t_map *map, t_vec raypos, t_vec raydir, int *tex_iter)
{
	t_dda value;
	t_vec delta;
	t_pos pos;

	pos.x = (int)raypos.x;
	pos.y = (int)raypos.y;
	delta.x = sqrt(1.0 + (raydir.y * raydir.y) / (raydir.x * raydir.x));
	delta.y = sqrt(1.0 + (raydir.x * raydir.x) / (raydir.y * raydir.y));
	value = init_dda(pos, delta, raypos, raydir);
	while (pos.x > -1 && pos.x < map->width
			&& pos.y > -1 && pos.y < map->height)
	{
		if (value.dx < value.dy)
		{
			value.dx += delta.x;
			pos.x += value.sx;
			value.side = 0;
		}
		else
		{
			value.dy += delta.y;
			pos.y += value.sy;
			value.side = 1;
		}
		if (map->grid[pos.x][pos.y] != 0)
			break ;
	}
	*tex_iter = get_tex_iter(value, raydir, pos, raydir);
	return (value.side == 0 ?
			fabs((pos.x - raypos.x + (1 - value.sx) / 2) / raydir.x) :
			fabs((pos.y - raypos.y + (1 - value.sy) / 2) / raydir.y));
}

void	ray(t_map *map)
{
	int		i;
	double	height;
	t_vec	raypos;
	t_vec	raydir;
	int		texx;

	i = 0;
	while (i < WIDTH)
	{
		raypos.x = map->pos.x;
		raypos.y = map->pos.y;
		raydir.x = map->dirvec.x + map->cvec.x * (double)(2.0 * i / WIDTH - 1);
		raydir.y = map->dirvec.y + map->cvec.y * (double)(2.0 * i / WIDTH - 1);
		height = dda(map, raypos, raydir, &texx);
		//printf(RED"i: %d|height: %f\n"RST, i,height);
		draw_wall_slice(map, get_pos(i, fabs(HEIGHT / height)), texx);
		i++;
	}
}
