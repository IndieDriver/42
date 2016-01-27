/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 10:30:38 by amathias          #+#    #+#             */
/*   Updated: 2016/01/27 11:30:55 by amathias         ###   ########.fr       */
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
	return (0);
}
