/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 12:09:49 by amathias          #+#    #+#             */
/*   Updated: 2016/02/15 12:01:19 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_map *map)
{
	if (map->key.mup == 1)
	{
		map->pow++;
		map->zoom *= pow(1.01, map->pow);
		draw(map);
	}
	if (map->key.mdown == 1)
	{
		map->pow = map->pow < 1 ? 1 : map->pow - 1;
		map->zoom = map->zoom < 1 ? 1 : map->zoom / pow(1.01, map->pow);
		draw(map);
	}
}

void	move(t_map *map)
{
	double tmpx;
	double tmpy;

	tmpx = map->mx;
	tmpy = map->my;
	if (map->key.up == 1)
		map->my -= 0.1;
	if (map->key.down == 1)
		map->my += 0.1;
	if (map->key.left == 1)
		map->mx -= 0.1;
	if (map->key.right == 1)
		map->mx += 0.1;
	if (tmpx != map->mx || tmpy != map->my)
		draw(map);
}
