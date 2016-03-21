/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:28:56 by amathias          #+#    #+#             */
/*   Updated: 2016/03/21 12:04:26 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		colide(t_map *map, int signe, int lat)
{
	if (!lat && map->grid[(int)(map->pos.x + (signe * map->dirvec.x) * 0.1)]
		[(int)(map->pos.y + (signe * map->dirvec.y) * 0.1)] > 0)
		return (1);
	if (lat && map->grid[(int)(map->pos.x - (signe * map->dirvec.y) * 0.1)]
			[(int)(map->pos.y + (signe * map->dirvec.x) * 0.1)] > 0)
		return (1);
	return (0);
}

void	rotate2(t_map *map)
{
	t_vec tmp;

	if (map->key.mright == 1)
	{
		tmp = map->dirvec;
		map->dirvec.x = tmp.x * cos(2 * M_PI / 180.0) -
			tmp.y * sin(2 * M_PI / 180.0);
		map->dirvec.y = tmp.x * sin(2 * M_PI / 180.0) +
			tmp.y * cos(2 * M_PI / 180.0);
		tmp = map->cvec;
		map->cvec.x = tmp.x * cos(2 * M_PI / 180.0) -
			tmp.y * sin(2 * M_PI / 180.0);
		map->cvec.y = tmp.x * sin(2 * M_PI / 180.0) +
			tmp.y * cos(2 * M_PI / 180.0);
		draw(map);
	}
}

void	rotate(t_map *map)
{
	t_vec tmp;

	if (map->key.mleft == 1)
	{
		tmp = map->dirvec;
		map->dirvec.x = tmp.x * cos(-2 * M_PI / 180.0) -
			tmp.y * sin(-2 * M_PI / 180.0);
		map->dirvec.y = tmp.x * sin(-2 * M_PI / 180.0) +
			tmp.y * cos(-2 * M_PI / 180.0);
		tmp = map->cvec;
		map->cvec.x = tmp.x * cos(-2 * M_PI / 180.0) -
			tmp.y * sin(-2 * M_PI / 180.0);
		map->cvec.y = tmp.x * sin(-2 * M_PI / 180.0) +
			tmp.y * cos(-2 * M_PI / 180.0);
		draw(map);
	}
	rotate2(map);
}

void	move(t_map *map)
{
	if (map->key.up == 1 && !colide(map, 1, 0))
	{
		map->pos.x += map->dirvec.x * 0.1;
		map->pos.y += map->dirvec.y * 0.1;
		draw(map);
	}
	if (map->key.down == 1 && !colide(map, -1, 0))
	{
		map->pos.x -= map->dirvec.x * 0.1;
		map->pos.y -= map->dirvec.y * 0.1;
		draw(map);
	}
	if (map->key.right == 1 && !colide(map, 1, 1))
	{
		map->pos.x += -map->dirvec.y * 0.1;
		map->pos.y += map->dirvec.x * 0.1;
		draw(map);
	}
	if (map->key.left == 1 && !colide(map, -1, 1))
	{
		map->pos.x -= -map->dirvec.y * 0.1;
		map->pos.y -= map->dirvec.x * 0.1;
		draw(map);
	}
}
