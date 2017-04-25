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
	if (map->key.left || map->key.right || map->key.up || map->key.down)
	{
		apply_trans(map->modelmat4, map->pos, map->rot);
		get_mvp(map->mvpmat4, map->modelmat4, map->viewmat4, map->projmat4);
		get_normalmat(map->normalmat4, map->modelmat4, map->viewmat4);
		draw(map);
	}
}
