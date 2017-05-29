/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 14:44:48 by amathias          #+#    #+#             */
/*   Updated: 2016/07/24 19:08:41 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		loop_hook(t_map *map)
{
	if (map->key.kspace > 0)
		map->key.kspace--;
	move(map);
	return (0);
}

void	key_press2(int keycode, t_map *map)
{
	if (keycode == 13)
		map->key.up = 1;
	if (keycode == 1)
		map->key.down = 1;
	if (keycode == 0)
		map->key.right = 1;
	if (keycode == 2)
		map->key.left = 1;
	if (keycode == 12)
		map->key.q = 1;
	if (keycode == 14)
		map->key.e = 1;
	if (keycode == 49)
		map->key.kspace = 60;
	if (keycode == 15)
		map->key.r = 1;
}

int		key_press(int keycode, t_map *map)
{
	if (keycode == 126)
		map->key.rup = 1;
	if (keycode == 125)
		map->key.rdown = 1;
	if (keycode == 123)
		map->key.rleft = 1;
	if (keycode == 124)
		map->key.rright = 1;
	if (keycode == 269)
		map->key.rcontrol = 1;
	if (keycode == 258)
		map->key.rshift = 1;
	key_press2(keycode, map);
	return (0);
}

int		expose_hook(t_map *map)
{
	draw(map);
	return (0);
}

int		red_cross(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	if (map->vertex_array)
		free(map->vertex_array);
	if (map->normal_array)
		free(map->normal_array);
	if (map->uv_array)
		free(map->uv_array);
	if (map->indice_array)
		free(map->indice_array);
	exit(0);
	return (0);
}
