/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_dist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:31:39 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 16:06:18 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	set_normal(t_cylinder s, t_vec ray, t_vec opos, double t)
{
	t_vec	nor;
	double	m;
	t_vec	inter;

	inter = ray_inter(ray, opos, t);
	m = (vec_dot(ray, s.axis) * t)
		+ vec_dot(vec_sub(opos, s.pos), s.axis);
	nor.x = (ray.x * t) + (opos.x - s.pos.x) - s.axis.x * m;
	nor.y = (ray.y * t) + (opos.y - s.pos.y) - s.axis.y * m;
	nor.z = (ray.z * t) + (opos.z - s.pos.z) - s.axis.z * m;
	vec_normalize(&nor);
	return (nor);
}

double	getdist_cyl(t_cylinder *s, t_vec ray, t_vec opos)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = vec_dot(ray, ray) -
		(vec_dot(ray, s->axis) * vec_dot(ray, s->axis));
	b = 2.0 * (vec_dot(ray, vec_sub(opos, s->pos))
			- (vec_dot(ray, s->axis) *
				vec_dot(vec_sub(opos, s->pos), s->axis)));
	c = vec_dot(vec_sub(opos, s->pos), vec_sub(opos, s->pos))
		- (vec_dot(vec_sub(opos, s->pos), s->axis)
		* vec_dot(vec_sub(opos, s->pos), s->axis))
		- s->radius * s->radius;
	d = (b * b) - (4 * a * c);
	if (d >= 0.0)
	{
		s->t = (-b + sqrt(d)) / (2.0 * a);
		if ((-b - sqrt(d)) / (2.0 * a) < s->t)
			s->t = (-b - sqrt(d)) / (2.0 * a);
		s->normal = set_normal(*s, ray, opos, s->t);
	}
	else
		return (-1.0);
	return (s->t);
}
