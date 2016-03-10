/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/10 15:21:17 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	raytrace(t_map *map, int x, int y)
{
	t_sphere *sh;
	t_sphere *light;
	t_vec 		inter;
	t_vec		ray;
	int			color;

	ray = ray_viewplane(map, x, y);
	sh = (t_sphere*)iter(map, ray, map->scene.pos);
	if (sh)
	{
		inter = ray_inter(map, ray, sh->t);
		light = (t_sphere*)iter(map, ray_light(inter, map->scene.light),
				map->scene.light);
		if (light)
		{
			color = sh->color;
			if (sh == light)
				color = get_color(sh, inter, ray_light(inter, map->scene.light),
						sh->color);
			else	
				color = get_shadow(map, sh, inter, color);
			
			if (sh->type == 1)
				color =	get_reflection(map, sh, ray_light(inter, map->scene.light),
					inter, color);
			draw_pixel_to_image(map, x, y, color);
		}
	}
}

void	raytracer(t_map *map)
{
	int x;
	int y;

	y = 0;
	map->scene.sphere[0].radius = 25.0;
	map->scene.sphere[1].radius = 25.0;
	map->scene.light.x = 250.0;
	map->scene.light.y = -200.0;
	map->scene.light.z = 250.0;
	while (y < map->scene.h)
	{
		x = 0;
		while (x < map->scene.w)
		{
			raytrace(map, x, y);
			x++;
		}
		y++;
	}
}
