/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/03 17:24:35 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
/*
t_vec	lightray(t_map *map, t_vec ray, double t)
{
	t_vec light;

	light.x = (map->scene.pos.x + ray.x * t) - map->scene.light.x;
	light.y = (map->scene.pos.y + ray.y * t) - map->scene.light.y;
	light.z = (map->scene.pos.z + ray.z * t) - map->scene.light.z;
	vec_normalize(&light);
	return (light);
}

t_vec	ray(t_map *map, int x, int y)
{
	t_vec ray;

	ray.x = (x - (map->scene.w / 2));
	ray.y = (y - (map->scene.h / 2));
	ray.z = -(map->scene.w / (2 * tan((45 / 2) * M_PI / 180.0)));
	return (ray);
}
*/
void	raytrace(t_map *map, int x, int y)
{
	t_sphere *shape;
	t_sphere *light;
	t_vec 		inter;
	t_vec		ray;

	ray = ray_viewplane(map, x, y);
	shape = (t_sphere*)iter(map, ray, map->scene.pos);
	if (shape)
	{
		inter = ray_inter(map, ray, shape->t);
		light = (t_sphere*)iter(map, ray_light(map, inter),
				map->scene.light);
		if (!light)
			draw_pixel_to_image(map, x, y, 0x000000);
		else
		{
			if (shape == light)
			{
				draw_pixel_to_image(map, x, y,
					get_color(shape,
						inter, ray_light(map, inter), shape->color));
			}
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
	map->scene.light.x = 20.0;
	map->scene.light.y = -20.0;
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
