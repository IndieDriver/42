/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/18 15:06:38 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		***init_tex_array(int nb)
{
	int ***tex_array;
	int i;

	i = 0;
	if (!(tex_array = (int***)malloc(sizeof(int**) * nb)))
		return (NULL);
	tex_array[0] = get_texture("assets/mossy.ppm", 64);
	tex_array[1] = get_texture("assets/greystone.ppm", 64);
	tex_array[2] = get_texture("assets/purplestone.ppm", 64);
	tex_array[3] = get_texture("assets/colorstone.ppm", 64);
	tex_array[4] = get_texture("assets/wood.ppm", 64);
	tex_array[5] = get_texture("assets/bluestone.ppm", 64);
	tex_array[6] = get_texture("assets/redbrick.ppm", 64);
	tex_array[7] = get_texture("assets/eagle.ppm", 64);
	tex_array[8] = get_texture("assets/barrel.ppm", 64);
	return (tex_array);
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
				map->tex[tex.id][(int)i][tex.x]);
		i += step;
		from.y++;
	}
}
