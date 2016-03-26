/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 15:18:33 by amathias          #+#    #+#             */
/*   Updated: 2016/03/26 14:21:40 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	ray_shadow(t_map *map, t_vec inter, double offset_x, double offset_y)
{
	t_vec sha;

	sha.x = (inter.x - map->scene.light->x) - offset_x;
	sha.y = (inter.y - map->scene.light->y) - offset_y;
	sha.z = (inter.z - map->scene.light->z);
	vec_normalize(&sha);
	return (sha);
}

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

double 	to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

t_vec	ray_viewplane(t_map *map, int x, int y)
{
	t_vec ray;
	t_vec tmp;
	double xrot = 0.0;
	double yrot = 0.0;
	double zrot = 0.0;
	ray.x = (x - (map->scene.w / 2));
	ray.y = (y - (map->scene.h / 2));
	ray.z = -(map->scene.w / (2 * tan((60 / 2) * M_PI / 180.0)));
	vec_normalize(&ray);
	//x-axis rotation
	tmp = ray;
	ray.x = tmp.x * cos(to_rad(xrot)) - tmp.y * sin(to_rad(xrot));
	ray.y = tmp.x * sin(to_rad(xrot)) + tmp.y * cos(to_rad(xrot));
	ray.z = tmp.z;
	//z-axis rotation
	tmp = ray;
	ray.y = tmp.y * cos(to_rad(zrot)) - tmp.z * sin(to_rad(zrot));
	ray.z = tmp.y * sin(to_rad(zrot)) + tmp.z * cos(to_rad(zrot));
	ray.x = tmp.x;
	//y-axis rotation
	tmp = ray;
	ray.z = tmp.z * cos(to_rad(yrot)) - tmp.x * sin(to_rad(yrot));
	ray.x = tmp.z * sin(to_rad(yrot)) + tmp.x * cos(to_rad(yrot));
	ray.y = tmp.y;
	return (ray);
}
