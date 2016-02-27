/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 17:05:14 by amathias          #+#    #+#             */
/*   Updated: 2016/02/27 17:26:09 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		move(t_map *map)
{
	if (map->key.up == 1)
		map->scene.pos.x += 1.0;
	if (map->key.down == 1)
		map->scene.pos.x -= 1.0;
	if (map->key.left == 1)
		map->scene.pos.y += 1.0;
	if (map->key.right == 1)
		map->scene.pos.y -= 1.0;
	draw(map);
}
