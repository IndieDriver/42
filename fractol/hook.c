/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 10:30:38 by amathias          #+#    #+#             */
/*   Updated: 2016/02/19 11:44:09 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		loop_hook(t_map *map)
{
	zoom(map);
	move(map);
	return (0);
}

int		expose_hook(t_map *map)
{
	draw(map);
	return (0);
}

int		motion_notify(int x, int y, t_map *map)
{
	if (x > 0 && y > 0 && x < WIDTH && y < WIDTH && map->type == 1)
	{
		map->c.real = 1.5 * (x - (WIDTH / 2)) / (WIDTH * map->zoom / 2);
		map->c.ima = 1.5 * (y - (HEIGHT / 2)) / (HEIGHT * map->zoom / 2);
		draw(map);
	}
	return (0);
}

int		key_press(int keycode, t_map *map)
{
	if (keycode == 0)
		map->key.left = 1;
	if (keycode == 1)
		map->key.down = 1;
	if (keycode == 2)
		map->key.right = 1;
	if (keycode == 13)
		map->key.up = 1;
	if (keycode == 24)
		map->key.iterplus = 1;
	if (keycode == 27)
		map->key.iterminus = 1;
	if (keycode == 30)
		map->key.mdown = 1;
	if (keycode == 42)
		map->key.mup = 1;

	return (0);
}

int		key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->env.mlx, map->env.win);
		exit(0);
	}
	if (keycode == 0)
		map->key.left = 0;
	if (keycode == 1)
		map->key.down = 0;
	if (keycode == 2)
		map->key.right = 0;
	if (keycode == 13)
		map->key.up = 0;
	if (keycode == 24)
		map->key.iterplus = 0;
	if (keycode == 27)
		map->key.iterminus = 0;
	if (keycode == 49)
	{
		map->iso = map->iso == 1 ? 0 : 1;
		draw(map);
	}
	if (keycode == 30)
		map->key.mdown = 0;
	if (keycode == 42)
		map->key.mup = 0;
	return (0);
}
