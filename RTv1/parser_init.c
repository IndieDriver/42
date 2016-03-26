/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 13:56:20 by amathias          #+#    #+#             */
/*   Updated: 2016/03/26 14:23:23 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_t_sphere(t_sphere *sph)
{
	sph->type = 1;
	sph->color = 0xFF0000;
	sph->pos.x = 0.0;
	sph->pos.y = 0.0;
	sph->pos.z = 0.0;
	sph->radius = 10.0;
}

void	init_t_plan(t_plan *plan)
{
	plan->type = 2;
	plan->color = 0x00FF00;
	plan->pos.x = 0.0;
	plan->pos.y = 0.0;
	plan->pos.z = 0.0;
	plan->normal.x = 0.0;
	plan->normal.y = 1.0;
	plan->normal.z = 0.0;
}

void	init_t_cylinder(t_cylinder *cyl)
{
	cyl->type = 3;
	cyl->color = 0xFFFF00;
	cyl->pos.x = 0.0;
	cyl->pos.y = 0.0;
	cyl->pos.z = 0.0;
	cyl->radius = 10.0;
	cyl->axis.x = 0.0;
	cyl->axis.y = 1.0;
	cyl->axis.z = 0.0;
}

void	init_t_cone(t_cone *cone)
{
	cone->type = 4;
	cone->color = 0x0000FF;
	cone->pos.x = 0.0;
	cone->pos.y = 0.0;
	cone->pos.z = 0.0;
	cone->k = 0.5;
	cone->axis.x = 0.0;
	cone->axis.y = 1.0;
	cone->axis.z = 0.0;
}
