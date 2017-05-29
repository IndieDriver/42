/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 14:44:48 by amathias          #+#    #+#             */
/*   Updated: 2016/07/24 19:08:41 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	key_hook2(int keycode, t_map *map)
{
	if (keycode == 13)
		map->key.up = 0;
	if (keycode == 1)
		map->key.down = 0;
	if (keycode == 0)
		map->key.right = 0;
	if (keycode == 2)
		map->key.left = 0;
	if (keycode == 12)
		map->key.q = 0;
	if (keycode == 14)
		map->key.e = 0;
}

int		key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
		red_cross(map);
	if (keycode == 126)
		map->key.rup = 0;
	if (keycode == 125)
		map->key.rdown = 0;
	if (keycode == 123)
		map->key.rleft = 0;
	if (keycode == 124)
		map->key.rright = 0;
	if (keycode == 269)
		map->key.rcontrol = 0;
	if (keycode == 258)
		map->key.rshift = 0;
	key_hook2(keycode, map);
	return (0);
}
