/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:03:06 by amathias          #+#    #+#             */
/*   Updated: 2016/03/12 16:00:47 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_normal_sphere(void *shape, t_vec inter)
{
	t_sphere *sph;
	t_vec nor;

	sph = shape;
	nor.x = inter.x - sph->pos.x;
	nor.y = inter.y - sph->pos.y;
	nor.z = inter.z - sph->pos.z;
	vec_normalize(&nor);
	return (nor);
}

t_vec	get_normal_cyl(void *shape)
{
	t_cylinder *cyl;

	cyl = shape;
	//printf("normal cyl\n");
	return (cyl->nor);
}

t_vec	get_normal_plan(void *shape)
{
	t_plan *plan;
	t_vec nor;
	
	plan = shape;
	nor.x = 0.0;
	nor.y = 1.0;
	nor.z = 0.0;
	vec_normalize(&nor);
	return (nor);
}

t_vec	get_normal(void *shape, t_vec inter)
{
	t_sphere *tmp;
	t_vec	vec;

	tmp = shape;
	if (tmp->type == 1)
		return (get_normal_sphere(shape, inter));
	else if (tmp->type == 2)
		return (get_normal_plan(shape));
	else if (tmp->type == 3)
		return (get_normal_cyl(shape));
	else
		return (vec);
}
