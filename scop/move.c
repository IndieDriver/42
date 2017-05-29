/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:28:56 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 11:51:58 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		move2(t_map *map)
{
	if (map->key.rup == 1)
		map->pos.x = map->pos.x + (0.1f);
	if (map->key.rdown == 1)
		map->pos.x = map->pos.x - (0.1f);
	if (map->key.rright == 1)
		map->pos.z = map->pos.z - (0.1f);
	if (map->key.rleft == 1)
		map->pos.z = map->pos.z + (0.1f);
	if (map->key.rshift == 1)
		map->pos.y = map->pos.y + (0.1f);
	if (map->key.rcontrol == 1)
		map->pos.y = map->pos.y - (0.1f);
	if (map->key.kspace == 1)
		map->has_texture = !map->has_texture;
	if (map->key.rleft || map->key.rright || map->key.rup || map->key.rcontrol
			|| map->key.rshift || map->key.rdown || map->key.kspace == 1)
		return (1);
	return (0);
}

void	move(t_map *map)
{
	if (map->key.up == 1)
		map->rot.x = map->rot.x + (0.1f);
	if (map->key.down == 1)
		map->rot.x = map->rot.x - (0.1f);
	if (map->key.right == 1)
		map->rot.y = map->rot.y + (0.1f);
	if (map->key.left == 1)
		map->rot.y = map->rot.y - (0.1f);
	if (map->key.q == 1)
		map->rot.z = map->rot.z - (0.1f);
	if (map->key.e == 1)
		map->rot.z = map->rot.z + (0.1f);
	map->pos = map->key.r == 1 ? map->init_pos : map->pos;
	map->rot = map->key.r == 1 ? get_vec4(0.0f, 0.0f, 0.0f, 0.0f) : map->rot;
	if (map->key.left || map->key.right || map->key.up || map->key.down
		|| map->key.q || map->key.e || map->key.r || move2(map))
	{
		apply_trans(map->modelmat4, map->pos, map->rot);
		get_mvp(map->mvpmat4, map->modelmat4, map->viewmat4, map->projmat4);
		get_normalmat(map->normalmat4, map->modelmat4, map->viewmat4);
		draw(map);
	}
}
