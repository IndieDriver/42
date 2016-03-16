/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:04:58 by amathias          #+#    #+#             */
/*   Updated: 2016/03/16 12:29:43 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


static t_vec	set_normal(t_cone s, t_vec ray, t_vec opos)
{
	t_vec nor;
	double m;
	t_vec axis;
	t_vec inter;

	inter = ray_inter(ray, opos, s.t);
	axis.x = 0.0;
	axis.y = -1.0;
	axis.z = 0.0;	
	vec_normalize(&axis);
	m = ((ray.x * axis.x + ray.y * axis.y + ray.z * axis.z) * s.t)
		+ ((opos.x - s.pos.x) * axis.x
		+ (opos.y - s.pos.y) * axis.y
		+ (opos.z - s.pos.z) * axis.z);
	nor.x = ((ray.x * s.t) + (opos.x - s.pos.x)) - (axis.x * m);
	nor.y = ((ray.y * s.t) + (opos.y - s.pos.y)) - (axis.y * m);
	nor.z = ((ray.z * s.t) + (opos.z - s.pos.z)) - (axis.z * m);
	vec_normalize(&nor);
	return (nor);
}

double	getdist_cone(t_cone *s, t_vec ray, t_vec opos)
{
	double a;
	double b;
	double c;
	double d;
	double t;
	t_vec axis;

	axis.x = 0.0;
	axis.y = -1.0;
	axis.z = 0.0;
	vec_normalize(&axis);
	s->k = 0.5;
	a = vec_dotproduct(ray,ray) - (1.0 + (s->k * s->k)) *
		(vec_dotproduct(ray, axis) * vec_dotproduct(ray, axis));
	b = 2.0 * (vec_dotproduct(ray, vec_sub(opos, s->pos))
			- (1.0 + (s->k * s->k))
			* (vec_dotproduct(ray, axis)
			* vec_dotproduct(vec_sub(opos, s->pos), axis)));
	c = vec_dotproduct(vec_sub(opos, s->pos), vec_sub(opos, s->pos))
		- (1.0 + (s->k * s->k)) *
		(vec_dotproduct(vec_sub(opos, s->pos), axis)
		* vec_dotproduct(vec_sub(opos, s->pos), axis));
	d = (b * b) - (4 * a * c);
	if (d >= 0.0)
	{
		t = (-b + sqrt(d)) / (2.0 * a);
		if ((-b - sqrt(d)) / (2.0 * a) < t)
			t = (-b - sqrt(d)) / (2.0 * a);
		s->t = t;
		s->nor = set_normal(*s, ray, opos);
	}
	else
		return (-1.0);
	return (t);
}
