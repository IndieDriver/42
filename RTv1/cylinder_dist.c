/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:31:39 by amathias          #+#    #+#             */
/*   Updated: 2016/03/18 12:16:07 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


t_vec	set_normal(t_cylinder s, t_vec ray, t_vec opos, double t)
{
	t_vec nor;
	double m;
	t_vec axis;
	t_vec inter;

	inter = ray_inter(ray, opos, t);
	axis.x = 0.0;
	axis.y = 1.0;
	axis.z = 0.0;	
	vec_normalize(&axis);
	m = (vec_dotproduct(ray, axis) * t)
		+ vec_dotproduct(vec_sub(opos, s.pos), axis);
	nor.x = (ray.x * t) + (opos.x - s.pos.x) - axis.x * m;
	nor.y = (ray.y * t) + (opos.y - s.pos.y) - axis.y * m;
	nor.z = (ray.z * t) + (opos.z - s.pos.z) - axis.z * m;
	vec_normalize(&nor);
	return (nor);
}

double	getdist_cyl(t_cylinder *s, t_vec ray, t_vec opos)
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
	a = vec_dotproduct(ray,ray) -
		(vec_dotproduct(ray, axis) * vec_dotproduct(ray, axis));
	b = 2.0 * (vec_dotproduct(ray, vec_sub(opos, s->pos))
			- (vec_dotproduct(ray, axis) *
				vec_dotproduct(vec_sub(opos, s->pos), axis)));
	c = vec_dotproduct(vec_sub(opos, s->pos), vec_sub(opos, s->pos))
		- (vec_dotproduct(vec_sub(opos, s->pos), axis)
		* vec_dotproduct(vec_sub(opos, s->pos), axis))
		- s->radius * s->radius;
	d = (b * b) - (4 * a * c);
	if (d >= 0.0)
	{
		t = (-b + sqrt(d)) / (2.0 * a);
		if ((-b - sqrt(d)) / (2.0 * a) < t)
			t = (-b - sqrt(d)) / (2.0 * a);
		s->t = t;
		s->normal = set_normal(*s, ray, opos, t);
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
