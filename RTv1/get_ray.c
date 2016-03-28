/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:18:33 by amathias          #+#    #+#             */
/*   Updated: 2016/03/28 14:16:18 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	ray_inter(t_vec ray, t_vec opos, double t)
{
	t_vec inter;

	inter.x = opos.x + ray.x * t;
	inter.y = opos.y + ray.y * t;
	inter.z = opos.z + ray.z * t;
	return (inter);
}

t_vec	ray_invlight(t_vec inter, t_vec light_pos)
{
	t_vec light;

	light.x = light_pos.x - inter.x;
	light.y = light_pos.y - inter.y;
	light.z = light_pos.z - inter.z;
	vec_normalize(&light);
	return (light);
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
	t_vec tmp;

	ray.x = (x - (map->scene.w / 2));
	ray.y = ((map->scene.h - y) - (map->scene.h / 2));
	ray.z = -(map->scene.w / (2 * tan((50 / 2) * M_PI / 180.0)));
	vec_normalize(&ray);
	tmp = ray;
	ray.x = tmp.x * cos(to_rad(map->scene.rot.z))
		- tmp.y * sin(to_rad(map->scene.rot.z));
	ray.y = tmp.x * sin(to_rad(map->scene.rot.z))
		+ tmp.y * cos(to_rad(map->scene.rot.z));
	tmp = ray;
	ray.y = tmp.y * cos(to_rad(map->scene.rot.x))
		- tmp.z * sin(to_rad(map->scene.rot.x));
	ray.z = tmp.y * sin(to_rad(map->scene.rot.x))
		+ tmp.z * cos(to_rad(map->scene.rot.x));
	tmp = ray;
	ray.z = tmp.z * cos(to_rad(map->scene.rot.y))
		- tmp.x * sin(to_rad(map->scene.rot.y));
	ray.x = tmp.z * sin(to_rad(map->scene.rot.y))
		+ tmp.x * cos(to_rad(map->scene.rot.y));
	vec_normalize(&ray);
	return (ray);
}
