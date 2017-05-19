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

int		key_press(int keycode, t_map *map)
{
	if (keycode == 126)
		map->key.rup = 1;
	if (keycode == 125)
		map->key.rdown = 1;
	if (keycode == 13)
		map->key.up = 1;
	if (keycode == 1)
		map->key.down = 1;
	if (keycode == 0)
		map->key.right = 1;
	if (keycode == 2)
		map->key.left = 1;
	if (keycode == 49)
		map->key.kspace = 60;
	return (0);
}

int		expose_hook(t_map *map)
{
	draw(map);
	return (0);
}

int		red_cross(t_map *map)
{
	glDeleteTextures(1, &map->texture_id);
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

int		key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
		red_cross(map);
	if (keycode == 126)
		map->key.rup = 0;
	if (keycode == 125)
		map->key.rdown = 0;
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
