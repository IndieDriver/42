/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/02/27 14:34:12 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_contact(t_map *map, t_sphere s, t_vec ray)
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
	if (d == 0.0)
		t = (-b + sqrt(d)) / (2 * a);
	else if (d > 0.0)
	{
		t = (-b + sqrt(d)) / (2 * a);
		if ((-b - sqrt(d)) / (2 * a) < t)
			t = (-b - sqrt(d)) / (2 * a);
	}
	else
		return (-1.0);
	return (t);
}



void	ray(t_map *map, int x, int y)
{
	//double	tmp;

	map->scene.rayvec.x = (x - (map->scene.w / 2)) * 1;
	map->scene.rayvec.y = (y - (map->scene.h / 2)) * 1;
	map->scene.rayvec.z = -(map->scene.w / (2 * tan((90 / 2) * M_PI / 180.0)));
	
	//tmp = get_contact(map, map->scene.rayvec);
	//draw_pixel_to_image(map, x, y, 0xFF0000);
}

void	iter_shape(t_map *map, int x, int y)
{
	double tmp;
	double t;
	int id;
	int i;

	i = 0;
	t = -1.0;
	id = -1;
	ray(map, x, y);
	while (i < 2)
	{
		tmp = get_contact(map, map->scene.sphere[i], map->scene.rayvec);
		if (tmp >= 0.0)
		{
			if (t == -1.0)
				t = tmp;
			if (tmp <= t)
			{
				t = tmp;
				id = i;
			}
		}
		i++;
	}
	if (id != -1)
		draw_pixel_to_image(map, x, y, map->scene.sphere[id].color);
}

void	raytracer(t_map *map)
{
	int x;
	int y;

	y = 0;
	map->scene.sphere[0].radius = 50.0;
	map->scene.sphere[1].radius = 75.0;
	while (y < map->scene.h)
	{
		x = 0;
		while (x < map->scene.w)
		{
			//ray(map, x, y);	
			iter_shape(map, x, y);
			x++;
		}
		y++;
	}
	printf("done\n");
}
