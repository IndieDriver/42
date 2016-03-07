/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/07 15:21:34 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	raytrace(t_map *map, int x, int y)
{
	t_sphere *sh;
	t_sphere *light;
	t_vec 		inter;
	t_vec		ray;

	ray = ray_viewplane(map, x, y);
	sh = (t_sphere*)iter(map, ray, map->scene.pos);
	if (sh)
	{
		inter = ray_inter(map, ray, sh->t);
		light = (t_sphere*)iter(map, ray_light(inter, map->scene.light),
				map->scene.light);
		if (light)
		{
			if (sh == light)
				draw_pixel_to_image(map, x, y,
					get_color(sh, inter, ray_light(inter, map->scene.light)
					, sh->color));
			else
				draw_pixel_to_image(map, x, y,
						get_shadow(map, sh, inter, map->scene.light));
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
	map->scene.light.x = -250.0;
	map->scene.light.y = -100.0;
	map->scene.light.z = -250.0;
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
