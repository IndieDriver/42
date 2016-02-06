/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/06 14:34:34 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_tex(t_map *map)
{
	map->texvalue.id = -1;
	map->texvalue.tex_iter = 0;	
}

void	draw_tex(t_map *map, t_pos from, t_pos to, t_tex tex)
{
	double	i;
	double	step;

	i = 0;
	step =  64.0 / (double)(to.y - from.y);
	//printf("step: %f\n", step);
	//printf("iter: %f\n", tex.tex_iter);
	while (from.y < to.y)
	{
		//printf("tex\n");
		//printf("i: %f\n",i);
		draw_pixel_to_image(map, from.x, from.y,
				map->tex[(int)i][(int)tex.tex_iter]);
		i += step;
		from.y++;
	}
}
