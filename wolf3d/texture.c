/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/17 15:37:57 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_tex(t_map *map)
{
	map->texvalue.id = -1;
	map->texvalue.x = 0;
}

void	draw_tex(t_map *map, t_pos from, t_pos to, t_tex tex)
{
	double	i;
	double	step;
	int		lheight;

	i = 0;
	step =  64.0 / (double)(to.y - from.y);
	lheight = (to.y - from.y);
	while (from.y < to.y)
	{
		draw_pixel_to_image(map, from.x, from.y,
				map->tex[(int)i][tex.x]);
		i += step;
		from.y++;
	}
}
