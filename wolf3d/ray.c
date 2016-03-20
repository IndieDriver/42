/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:40:41 by amathias          #+#    #+#             */
/*   Updated: 2016/03/20 15:57:51 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_dda	init_dda(t_pos pos, t_vec delta, t_vec raypos, t_vec raydir)
{
	t_dda value;

	value.side = 0;
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

double	dda(t_map *map, t_vec raypos, t_vec raydir, t_dda *value)
{
	t_vec delta;
	t_pos pos;

	pos.x = (int)raypos.x;
	pos.y = (int)raypos.y;
	delta.x = sqrt(1.0 + (raydir.y * raydir.y) / (raydir.x * raydir.x));
	delta.y = sqrt(1.0 + (raydir.x * raydir.x) / (raydir.y * raydir.y));
	*value = init_dda(pos, delta, raypos, raydir);
	while (pos.x > -1 && pos.x < map->height
		&& pos.y > -1 && pos.y < map->width)
	{
		value->side = value->dx < value->dy ? 0 : 1;
		value->dx = !value->side ? value->dx + delta.x : value->dx;
		value->dy = !value->side ? value->dy : value->dy + delta.y;
		pos.x = !value->side ? pos.x + value->sx : pos.x;
		pos.y = !value->side ? pos.y : pos.y + value->sy;
		if (map->grid[pos.x][pos.y] != 0)
			break ;
	}
	value->pos = get_pos(pos.x, pos.y);
	return (value->side == 0 ?
			fabs((pos.x - raypos.x + (1 - value->sx) / 2) / raydir.x) :
			fabs((pos.y - raypos.y + (1 - value->sy) / 2) / raydir.y));
}

void	ray(t_args *a)
{
	double	height;
	t_vec	raypos;
	t_vec	rdir;
	t_dda	value;
	t_tex	tex;

	while (a->min.x < a->max.x)
	{
		raypos.x = a->m->pos.x;
		raypos.y = a->m->pos.y;
		rdir.x = a->m->dirvec.x + a->m->cvec.x * (2.0 * a->min.x / WIDTH - 1);
		rdir.y = a->m->dirvec.y + a->m->cvec.y * (2.0 * a->min.x / WIDTH - 1);
		height = dda(a->m, raypos, rdir, &value);
		if (value.side == 0)
			tex.wallcord = raypos.y + height * rdir.y;
		else
			tex.wallcord = raypos.x + height * rdir.x;
		tex.x = (int)((tex.wallcord - floor(tex.wallcord)) * 64.0);
		if ((value.side == 0 && rdir.x > 0) || (value.side && rdir.y < 0))
			tex.x = 64 - tex.x - 1;
		tex.id = a->m->grid[value.pos.x][value.pos.y] - 1;
		draw_wall_slice(a->m, get_pos(a->min.x, fabs(HEIGHT / height)), tex);
		a->min.x++;
	}
}
