/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/02/26 06:58:53 by amathias         ###   ########.fr       */
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

double	get_contact(t_map *map, t_vec ray)
{
	t_sphere s;
	double a;
	double b;
	double c;
	double d;

	s = map->scene.sphere[0];
	a = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
	b = 2 * (ray.x * (map->scene.pos.x - s.pos.x)
		+ ray.y * (map->scene.pos.y - s.pos.y)
		+ ray.z * (map->scene.pos.z - s.pos.z));
	c = (map->scene.pos.x - s.pos.x) * (map->scene.pos.x - s.pos.x)
		+ (map->scene.pos.y - s.pos.y) * (map->scene.pos.y - s.pos.y)
		+ (map->scene.pos.z - s.pos.z) * (map->scene.pos.z - s.pos.z)
		- s.radius * s.radius;
	d = (b * b) - (4 * a * c);

		/*inter.x = (rayvec.x * rayvec.x) + (rayvec.y * rayvec.y) + (rayvec.z * rayvec.z);
		  inter.y = 2 * (rayvec.x * (map->scene.pos.x - 0.0) +
		  rayvec.y * (map->scene.pos.y - 0.0) + rayvec.z *
		  (map->scene.pos.z - 0.0));
		  inter.z = ((map->scene.pos.x - 0.0) * (map->scene.pos.x - 0.0) +
		  (map->scene.pos.y - 0.0) * (map->scene.pos.y - 0.0) +
		  (map->scene.pos.z - 0.0) * (map->scene.pos.z - 0.0)) - (125.0) * (125.0);
		  det = (inter.y * inter.y) - 4.0 * inter.x * inter.z; */
		//if (d > 0.0)
	printf("det: %f\n", d);
	return (d);
}



void	ray(t_map *map, int x, int y)
{
	double	tmp;

	map->scene.rayvec.x = (double)(x - (map->scene.w / 2.0) * 1);
	map->scene.rayvec.y = (double)(y - (map->scene.h / 2.0) * 1);
	map->scene.rayvec.z = -(map->scene.w / 2 * tan((90.0 / 2.0) * M_PI / 180.0));
	//normalize_vec(&(map->scene.rayvec));
	tmp = get_contact(map, map->scene.rayvec);
	if (tmp > 0.0)
		draw_pixel_to_image(map, x, y, 0xFF0000);
	//printf("x: %f| y: %f\n", rayvec.x, rayvec.y);
}

void	raytracer(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->scene.h)
	{
		x = 0;
		while (x < map->scene.w)
		{
			ray(map, x, y);	
			x++;
		}
		y++;
	}
	printf("done\n");
}
