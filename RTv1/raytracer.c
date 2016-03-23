/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/23 18:27:06 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_distance(t_vec p1, t_vec p2)
{
	double dist;

	dist = sqrt(vec_dot(vec_sub(p2, p1), vec_sub(p2, p1)));
	return (dist);
}

int		iter_spot(t_map *map, t_sphere *sh, t_sphere *light, t_vec inter)
{
	int color;

	color = sh->color;
	if (light)
	{
		if (sh == light)
		{
			color = get_diffuse(sh, ray_invlight(inter, *map->scene.light),
				color);
			color = get_reflection(sh, ray_invlight(inter, *map->scene.light),
				vec_sub(map->scene.pos, inter), color);
		}
		else
			color = get_shadow(map, sh, inter, color);
	}
	return (color);
}

int		raytrace(t_map *map, t_vec ray)
{
	t_sphere	*sh;
	t_sphere	*light;
	t_vec		inter;
	int			i;
	int			acolor[map->scene.nb_spot];

	i = 0;
	sh = (t_sphere*)iter(map, ray, map->scene.pos, 1);
	if (sh)
	{
		inter = ray_inter(ray, map->scene.pos, sh->t);
		sh->normal = get_normal(sh, inter);
		while (i < map->scene.nb_spot)
		{
			map->scene.light = &(map->scene.spot[i]);
			light = (t_sphere*)iter(map, ray_light(inter, *map->scene.light),
					*map->scene.light, 0);
			acolor[i] = iter_spot(map, sh, light, inter);
			i++;
		}
		return (average_rgb(acolor, i));
	}
	return (0x000000);
}

void	raytracer(t_map *map)
{
	t_vec	ray;
	int		color;
	int		x;
	int		y;

	y = 0;
	while (y < map->scene.h)
	{
		x = 0;
		while (x < map->scene.w)
		{
			ray = ray_viewplane(map, x, y);
			color = raytrace(map, ray);
			draw_pixel_to_image(map, x, y, color);
			x++;
		}
		y++;
	}
}
