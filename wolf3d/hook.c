/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 10:30:38 by amathias          #+#    #+#             */
/*   Updated: 2016/02/04 18:12:46 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_hook(t_map *map)
{
	draw(map);
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
	{
		map->pos.x += map->dirvec.x * 0.1;
		map->pos.y += map->dirvec.y * 0.1;
		draw(map);
	}
	if (keycode == 1)
	{	
		map->pos.x -= map->dirvec.x * 0.1;
		map->pos.y -= map->dirvec.y * 0.1;
		draw(map);
	}
	/*if (keycode == 0)
	{
		map->cpos.y--;
		draw(map);
	}
	if (keycode == 2)
	{
		map->cpos.y++;
		draw(map);
	} */

	return (0);
}
