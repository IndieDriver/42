/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/02 16:31:15 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	normalize_vec(t_vec *vec)
{
	double tmp;

	tmp = 1.0 / sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
	vec->x *= tmp;
	vec->y *= tmp;
	vec->z *= tmp;
}

t_vec	lightray(t_map *map, t_vec ray, double t)
{
	t_vec light;

	light.x = (map->scene.pos.x + ray.x * t) - map->scene.light.x;
	light.y = (map->scene.pos.y + ray.y * t) - map->scene.light.y;
	light.z = (map->scene.pos.z + ray.z * t) - map->scene.light.z;
	normalize_vec(&light);
	return (light);
}

t_vec	ray(t_map *map, int x, int y)
{
	t_vec ray;

	ray.x = (x - (map->scene.w / 2)) * 1;
	ray.y = (y - (map->scene.h / 2)) * 1;
	ray.z = -(map->scene.w / (2 * tan((45 / 2) * M_PI / 180.0)));
	return (ray);
}

void	raytrace(t_map *map, int x, int y)
{
	t_sphere *shape;
	t_sphere *light;

	shape = (t_sphere*)iter(map, ray(map, x, y), map->scene.pos);
	if (shape)
	{
		light = (t_sphere*)iter(map, lightray(map, ray(map, x, y), shape->t),
				map->scene.light);
		if (!light)
			draw_pixel_to_image(map, x, y, 0xFFFFFF);
		else
			draw_pixel_to_image(map, x, y, shape->color);
	}
}

void	raytracer(t_map *map)
{
	int x;
	int y;

	y = 0;
	map->scene.sphere[0].radius = 25.0;
	map->scene.sphere[1].radius = 25.0;
	map->scene.light.x = 0.0;
	map->scene.light.y = -200.0;
	map->scene.light.z = 600.0;
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
