/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:31:39 by amathias          #+#    #+#             */
/*   Updated: 2016/03/12 15:03:19 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


double	getdist_cyl(t_cylinder s, t_vec ray, t_vec opos)
{
	double a;
	double b;
	double c;
	double d;
	double t;
	t_vec axis;

	axis.x = 0.0;
	axis.y = 1.0;
	axis.z = 0.0;
	vec_normalize(&axis);
	s.radius = 10.0;
	a = (ray.x * ray.x + ray.y * ray.y + ray.z * ray.z) -
		((ray.x * axis.x + ray.y * axis.y + ray.z * axis.z) *
		(ray.x * axis.x + ray.y * axis.y + ray.z * axis.z));
	b = 2.0 * ((ray.x * (opos.x - s.pos.x)
		+ ray.y * (opos.y - s.pos.y)
		+ ray.z * (opos.z - s.pos.z)) -
		((ray.x * axis.x + ray.y * axis.y + ray.z * axis.z) *
		 ((opos.x - s.pos.x) * axis.x + (opos.y - s.pos.y) * axis.y) +
		 (opos.z - s.pos.z) * axis.z));
	c = (opos.x - s.pos.x) * (opos.x - s.pos.x)
		+ (opos.y - s.pos.y) * (opos.y - s.pos.y)
		+ (opos.z - s.pos.z) * (opos.z - s.pos.z) -
		(((opos.x - s.pos.x) * axis.x + (opos.y - s.pos.y) * axis.y +
		(opos.z - s.pos.z) * axis.z) *
		((opos.x - s.pos.x) * axis.x + (opos.y - s.pos.y) * axis.y +
		(opos.z - s.pos.z) * axis.z))
		- s.radius * s.radius;
	d = (b * b) - (4 * a * c);
	//printf("a: %f|b: %f|c: %f|d: %f\n",a,b,c,d);
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

/*
double	getdist_cyl(t_cylinder cyl, t_vec ray, t_vec opos)
{
	double t;
	t_vec axis;
	double r;
	t_sphere s;

	r = 20.0;
	axis.x = 0.0;
	axis.y = 1.0;
	axis.z = 0.0;
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
}
*/
