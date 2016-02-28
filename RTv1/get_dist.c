/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:41:56 by amathias          #+#    #+#             */
/*   Updated: 2016/02/28 13:52:17 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	getdist_sph(t_map *map, t_sphere s, t_vec ray)
{
	double a;
	double b;
	double c;
	double d;
	double t;

	a = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
	b = 2.0 * (ray.x * (map->scene.pos.x - s.pos.x)
		+ ray.y * (map->scene.pos.y - s.pos.y)
		+ ray.z * (map->scene.pos.z - s.pos.z));
	c = (map->scene.pos.x - s.pos.x) * (map->scene.pos.x - s.pos.x)
		+ (map->scene.pos.y - s.pos.y) * (map->scene.pos.y - s.pos.y)
		+ (map->scene.pos.z - s.pos.z) * (map->scene.pos.z - s.pos.z)
		- s.radius * s.radius;
	d = (b * b) - (4 * a * c);
	if (d >= 0.0)
	{
		t = (-b + sqrt(d)) / (2 * a);
		if ((-b - sqrt(d)) / (2 * a) < t)
			t = (-b - sqrt(d)) / (2 * a);
	}
	else
		return (-1.0);
	return (t);
}

double	getdist_plan(t_map *map, t_plan plan, t_vec ray)
{
	t_vec nor;
	double t;
	
	(void)plan;
	(void)map;
	nor.x = 0.0;
	nor.y = 1.0;
	nor.z = 0.0;
	t = -(((nor.x * (map->scene.pos.x - 0.0)) +
			(nor.y * (map->scene.pos.y - 0.0)) +
			 (nor.z * (map->scene.pos.z - 0.0)))
			/ ((nor.x * ray.x) + (nor.y * ray.y) + (nor.z * ray.z)));
	if (t < 0.0)
		return (-1.0);
	//printf("t: %f\n", t);
	return (t);
}
