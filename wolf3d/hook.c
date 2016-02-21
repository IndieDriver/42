/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 10:30:38 by amathias          #+#    #+#             */
/*   Updated: 2016/02/21 14:37:33 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_key(t_map *map)
{
	map->key.up = 0;
	map->key.down = 0;
	map->key.left = 0;
	map->key.right = 0;
	map->key.mleft = 0;
	map->key.mright = 0;
}

int		expose_hook(t_map *map)
{
	draw(map);
	return (0);
}

int		loop_hook(t_map *map)
{
	move(map);
	rotate(map);
	return (0);
}

int		key_press(int keycode, t_map *map)
{
	if (!map->pause)
	{
		if (keycode == 124)
			map->key.mleft = 1;
		if (keycode == 123)
			map->key.mright = 1;
		if (keycode == 13)
			map->key.up = 1;
		if (keycode == 1)
			map->key.down = 1;
		if (keycode == 0)
			map->key.right = 1;
		if (keycode == 2)
			map->key.left = 1;
		if (keycode == 36)
		{
			map->multithread = map->multithread == 0 ? 1 : 0;
			printf("multithread: %d\n", map->multithread);
		}
	}
	if (keycode == 35)
	{
		map->pause = map->pause == 0 ? 1 : 0;
		init_key(map);
		draw(map);
	}
	return (0);
}
int		key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->env.mlx, map->env.win);
		exit(0);
	}
	if (!map->pause)
	{
		if (keycode == 124)
			map->key.mleft = 0;
		if (keycode == 123)
			map->key.mright = 0;
		if (keycode == 13)
			map->key.up = 0;
		if (keycode == 1)
			map->key.down = 0;
		if (keycode == 0)
			map->key.right = 0;
		if (keycode == 2)
			map->key.left = 0;
	}
	return (0);
}
