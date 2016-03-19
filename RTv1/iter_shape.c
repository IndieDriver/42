/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:22:34 by amathias          #+#    #+#             */
/*   Updated: 2016/03/19 13:34:10 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_sphere	*iter_sph(t_map *map, t_vec ray, t_vec opos)
{
	int id;
	int i;

	i = 0;
	id = -1;
	while (i < map->scene.nb_sph)
	{
		map->scene.sphere[i].t = getdist_sph(map->scene.sphere[i], ray, opos);
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

t_plan	*iter_plan(t_map *map, t_vec ray, t_vec opos)
{
	int id;
	int i;

	i = 0;
	id = -1;
	while (i < map->scene.nb_plan)
	{
		map->scene.plan[i].t = getdist_plan(map->scene.plan[i], ray, opos);
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

t_cylinder	*iter_cyl(t_map *map, t_vec ray, t_vec opos)
{
	int id;
	int i;

	i = 0;
	id = -1;
	while (i < map->scene.nb_cyl)
	{
		map->scene.cylinder[i].t = getdist_cyl(&(map->scene.cylinder[i]), ray, opos);
		if (map->scene.cylinder[i].t >= 0.0)
		{
			if (id == -1)
				id = i;
			if (map->scene.cylinder[i].t <= map->scene.cylinder[id].t)
				id = i;
		}
		i++;
	}
	if (id != -1)
		return (&(map->scene.cylinder[id]));
	return (NULL);
}

t_cone	*iter_cone(t_map *map, t_vec ray, t_vec opos)
{
	int id;
	int i;

	i = 0;
	id = -1;
	while (i < map->scene.nb_cone)
	{
		map->scene.cone[i].t = getdist_cone(&(map->scene.cone[i]), ray, opos);
		if (map->scene.cone[i].t >= 0.0)
		{
			if (id == -1)
				id = i;
			if (map->scene.cone[i].t <= map->scene.cone[id].t)
				id = i;
		}
		i++;
	}
	if (id != -1)
		return (&(map->scene.cone[id]));
	return (NULL);
}

void	*iter(t_map *map, t_vec ray, t_vec opos)
{
	t_sphere	*sph;
	t_plan		*plan;
	t_cylinder	*cyl;
	t_cone		*cone;
	t_plan		*nearest;
	
	cyl = iter_cyl(map, ray, opos);
	cone = iter_cone(map, ray, opos);
	sph = iter_sph(map, ray, opos);
	plan = iter_plan(map, ray, opos);
	nearest = get_nearest(sph, plan, cyl, cone);
	if (!nearest)
		return (NULL);
	nearest->normal = get_normal(nearest, ray_inter(ray, opos, nearest->t));
	return (nearest);
}
