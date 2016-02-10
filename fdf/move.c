/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 13:13:45 by amathias          #+#    #+#             */
/*   Updated: 2016/02/10 14:03:05 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_move(t_map *map)
{
	int sx;
	int sy;

	sx = 0;
	sy = 0;
	if (map->key.up == 1)
		sy -= 3;
	if (map->key.down == 1)
		sy += 3;
	if (map->key.left == 1)
		sx += 3;
	if (map->key.right == 1)
		sx -= 3;
	if (sx != 0 || sy != 0)
		move(map, sx, sy);
}

void	move(t_map *map, int sx, int sy)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->grid[i][j].x += sx;
			map->grid[i][j].y += sy;
			j++;
		}
		i++;
	}
	draw(map);
}
