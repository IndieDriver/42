/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/07 14:58:32 by amathias         ###   ########.fr       */
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
	double	y;
	int		lheight;

	i = 0;
	step =  64.0 / (double)(to.y - from.y);
	lheight = (to.y - from.y);
	//printf("step: %f\n", step);
	y = tex.x;
	printf("iter: %f\n", y);
	while (from.y < to.y)
	{
   		//y = (from.y * 2 - HEIGHT + lheight) * (64 / 2) / lheight;
		//printf("y: %d\n", y);aaaaaa
		draw_pixel_to_image(map, from.x, from.y,
				map->tex[(int)i][(int)y]);
		i += step;
		from.y++;
	}
}
