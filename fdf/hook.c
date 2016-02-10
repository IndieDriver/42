/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:55:20 by amathias          #+#    #+#             */
/*   Updated: 2016/02/10 14:02:44 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_key(t_map *map)
{
	map->key.up = 0;
	map->key.down = 0;
	map->key.left = 0;
	map->key.right = 0;
}

int		loop_hook(t_map *map)
{
	get_move(map);
	return (0);
}

int		expose_hook(t_map *map)
{
	draw(map);
	return (0);
}

int		key_press(int keycode, t_map *map)
{
	if (keycode == 13)
		map->key.up = 1;
	if (keycode == 1)
		map->key.down = 1;
	if (keycode == 0)
		map->key.right = 1;
	if (keycode == 2)
		map->key.left = 1;
	return (0);
}

int		key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->env.mlx, map->env.win);
		exit(0);
	}
	if (keycode == 13)
		map->key.up = 0;
	if (keycode == 1)
		map->key.down = 0;
	if (keycode == 0)
		map->key.right = 0;
	if (keycode == 2)
		map->key.left = 0;
	return (0);
}
