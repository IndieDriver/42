/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:28:56 by amathias          #+#    #+#             */
/*   Updated: 2016/02/05 11:53:31 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

void	move(t_map *map)
{

	if (map->key.up == 1)
	{
		map->pos.x += map->dirvec.x * 0.1;
		map->pos.y += map->dirvec.y * 0.1;
		draw(map);
	}
	if (map->key.down == 1)
	{	
		map->pos.x -= map->dirvec.x * 0.1;
		map->pos.y -= map->dirvec.y * 0.1;
		draw(map);
	}
	if (map->key.right == 1)
	{
		map->pos.x += -map->dirvec.y * 0.1;
		map->pos.y += map->dirvec.x * 0.1;
		draw(map);
	}
	if (map->key.left == 1)
	{	
		map->pos.x -= -map->dirvec.y * 0.1;
		map->pos.y -= map->dirvec.x * 0.1;
		draw(map);
	}
}

