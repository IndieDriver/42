/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:18:33 by amathias          #+#    #+#             */
/*   Updated: 2016/03/07 14:18:48 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	ray_shadow(t_map *map, t_vec inter, double offset_x, double offset_y)
{
	t_vec sha;

	sha.x = (inter.x - map->scene.light.x) - offset_x;
	sha.y = (inter.y - map->scene.light.y) - offset_y;
	sha.z = (inter.z - map->scene.light.z);
	vec_normalize(&sha);
	return (sha);
}

t_vec	ray_inter(t_map *map, t_vec ray, double t)
{
	t_vec inter;

	inter.x = map->scene.pos.x + ray.x * t;
	inter.y = map->scene.pos.y + ray.y * t;
	inter.z = map->scene.pos.z + ray.z * t;
	return (inter);
}

t_vec	ray_light(t_vec inter, t_vec light_pos)
{
	t_vec light;

	light.x = inter.x - light_pos.x;
	light.y = inter.y - light_pos.y;
	light.z = inter.z - light_pos.z;
	vec_normalize(&light);
	return (light);
}

t_vec	ray_viewplane(t_map *map, int x, int y)
{
	t_vec ray;

	ray.x = (x - (map->scene.w / 2));
	ray.y = (y - (map->scene.h / 2));
	ray.z = -(map->scene.w / (2 * tan((45 / 2) * M_PI / 180.0)));
	vec_normalize(&ray);
	return (ray);
}

