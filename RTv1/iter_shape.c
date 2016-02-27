/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:22:34 by amathias          #+#    #+#             */
/*   Updated: 2016/02/27 17:04:43 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*iter_sph(t_map *map)
{
	int id;
	int i;

	i = 0;
	id = -1;
	while (i < map->scene.nb_sph)
	{
		map->scene.sphere[i].t =
			getdist_sph(map, map->scene.sphere[i], map->scene.rayvec);
		if (map->scene.sphere[i].t >= 0.0)
		{
			if (id == -1)
				id = i;
			if (map->scene.sphere[i].t <= map->scene.sphere[id].t)
				id = i;
		}
		i++;
	}
	if (id != -1)
		return (&map->scene.sphere[id]);
	return (NULL);
}

t_plan	*iter_plan(t_map *map)
{
	int id;
	int i;

	i = 0;
	id = -1;
	while (i < map->scene.nb_plan)
	{
		map->scene.plan[i].t =
			getdist_plan(map, map->scene.plan[i], map->scene.rayvec);
		if (map->scene.plan[i].t >= 0.0)
		{
			if (id == -1)
				id = i;
			if (map->scene.plan[i].t <= map->scene.plan[id].t)
				id = i;
		}
		i++;
	}
	if (id != -1)
		return (&map->scene.plan[id]);
	return (NULL);
}

void	iter(t_map *map, int x, int y)
{
	t_sphere	*sph;
	t_plan		*plan;
	//t_cylinder	*cyl;
	//t_cone		*cone;

	sph = iter_sph(map);
	plan = iter_plan(map);
	if (plan)
		draw_pixel_to_image(map, x, y, plan->color);
	if (sph)
		draw_pixel_to_image(map, x, y, sph->color);
}
