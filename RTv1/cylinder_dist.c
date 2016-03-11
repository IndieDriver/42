/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:31:39 by amathias          #+#    #+#             */
/*   Updated: 2016/03/11 15:51:14 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	getdist_cyl(t_cylinder cyl, t_vec ray, t_vec opos)
{
	double a;
	double b;
	double c;
	double d;
	double t;
	t_vec axis;
	double r;
	t_sphere s;

	r = 25.0;
	axis.x = 0.1;
	axis.y = 1.0;
	axis.z = 0.1;
	vec_normalize(&axis);
	cyl.pos = vec_sub(cyl.pos, vec_project(cyl.pos, axis));
	opos = vec_sub(opos, vec_project(opos, axis));
	ray = vec_sub(ray, vec_project(ray, axis));
	s.pos = cyl.pos;
	//printf("cyl.pos.x: %f| cyl.pos.y: %f| cyl.pos.z: %f\n", cyl.pos.x, cyl.pos.y, cyl.pos.z);
	s.radius = r;
	//printf("t: %f\n", getdist_sph(s, ray, opos));
	t = getdist_sph(s, ray, opos);
	return (t);
	//a = (ray.x * ray.x + ray.z * ray.z);
	//b = 2 * (ray.x * (opos.x - cyl.pos.x) + ray.z * (opos.z - cyl.pos.z));
	//c = (((opos.x - cyl.pos.x) * (opos.x - cyl.pos.x)) +
		//((opos.z - cyl.pos.z) * (opos.z - cyl.pos.z))) - r * r;
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

