/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 12:09:49 by amathias          #+#    #+#             */
/*   Updated: 2016/02/20 16:43:57 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_key(t_map *map)
{
	map->key.up = 0;
	map->key.down = 0;
	map->key.left = 0;
	map->key.right = 0;
	map->key.mup = 0;
	map->key.mdown = 0;
	map->key.iterminus = 0;
	map->key.iterplus = 0;
}

int		mouse_hook(int keycode, int x, int y, t_map *map)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (keycode == 5 || keycode == 1)
			map->zoom *= 1.3;
		if (keycode == 4 || keycode == 2)
			map->zoom /= 1.3;
		draw(map);
	}
	return (0);
}

void	zoom(t_map *map)
{
	if (map->key.iterplus == 1)
	{
		map->max_iter++;
		draw(map);
	}
	if (map->key.iterminus == 1)
	{
		map->max_iter = map->max_iter - 1 > -1 ? map->max_iter - 1 : 0;
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
		map->my -= 0.01;
	if (map->key.down == 1)
		map->my += 0.01;
	if (map->key.left == 1)
		map->mx -= 0.01;
	if (map->key.right == 1)
		map->mx += 0.01;
	if (tmpx != map->mx || tmpy != map->my)
		draw(map);
}
