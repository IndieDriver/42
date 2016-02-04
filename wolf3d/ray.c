/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:40:41 by amathias          #+#    #+#             */
/*   Updated: 2016/02/04 18:02:07 by amathias         ###   ########.fr       */
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

double	dda(t_map *map, t_vec raypos, t_vec raydir)
{
	t_dda value;
	t_vec delta;
	t_pos pos;

	pos.x = (int)raypos.x;
	pos.y = (int)raypos.y;
	delta.x = sqrt(1.0 + (raydir.y * raydir.y) / (raydir.x * raydir.x));
	delta.y = sqrt(1.0 + (raydir.x * raydir.x) / (raydir.y * raydir.y));
	value = init_dda(pos, delta, raypos, raydir);
	printf("delta.x: %f, delta.y: %f\n", delta.x, delta.y);
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
		printf("pos.x: %d|pos.y: %d\n",pos.x, pos.y);
		if (map->grid[pos.x][pos.y] != 0)
			break ;
	}
	printf("pos.x: %d, pos.y: %d, raypos.x: %f, raypos.y: %f, value.sx: %d, value.sy: %d, raydir.x: %f, raydir.y: %f\n",pos.x, pos.y,raypos.x, raypos.y, value.sx, value.sy, raydir.x, raydir.y);
	printf("result: %f| %f\n",
			fabs((pos.x - raypos.x + (double)(1 - value.sx) / 2) / raydir.x),
		fabs((pos.y - raypos.y + (double)(1 - value.sy) / 2) / raydir.y));
	return (value.side == 0 ?
			fabs((pos.x - raypos.x + (1 - value.sx) / 2) / raydir.x) :
			fabs((pos.y - raypos.y + (1 - value.sy) / 2) / raydir.y));
}

void	ray(t_map *map)
{
	int i;
	double height;

	t_vec raypos;
	t_vec raydir;

	i = 0;
	while (i < WIDTH)
	{
		raypos.x = map->pos.x;
		raypos.y = map->pos.y;
		raydir.x = map->dirvec.x + map->cvec.x * (double)(2.0 * i / WIDTH - 1);
		raydir.y = map->dirvec.y + map->cvec.y * (double)(2.0 * i / WIDTH - 1);
		printf("raydir.x: %f, raydir.y: %f\n", raydir.x, raydir.y);
		height = dda(map, raypos, raydir);
		printf(RED"i: %d|height: %f\n"RST, i,height);
		draw_wall_slice(map, i, fabs(HEIGHT / height)/*1.0 / height * 255 */);
		i++;
	}
}
