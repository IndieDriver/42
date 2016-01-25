/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 10:30:38 by amathias          #+#    #+#             */
/*   Updated: 2016/01/25 11:32:01 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wold3d.h"

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

int		key_hook(int keycode, t_map *map)
{
	if (keycode == 24)
	{
		map->pow++;
		map->zoom *= pow(1.001, map->pow);
		draw(map);
	}
	if (keycode == 27)
	{
		map->pow = map->pow < 1 ? 1 : map->pow - 1;
		map->zoom = map->zoom < 1 ? 1 : map->zoom / pow(1.001, map->pow);
		draw(map);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(map->env.mlx, map->env.win);
		exit(0);
	}
	return (0);
}
