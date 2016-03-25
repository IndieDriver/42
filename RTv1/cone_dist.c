/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 14:04:58 by amathias          #+#    #+#             */
/*   Updated: 2016/03/25 13:45:43 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vec	set_normal(t_cone s, t_vec ray, t_vec opos)
{
	t_vec	nor;
	double	m;
	t_vec	inter;

	inter = ray_inter(ray, opos, s.t);
	m = (vec_dot(ray, s.axis) * s.t)
		+ vec_dot(vec_sub(opos, s.pos), s.axis);
	nor.x = ((ray.x * s.t) + (opos.x - s.pos.x)) -
		((1.0 + (s.k * s.k)) * s.axis.x * m);
	nor.y = ((ray.y * s.t) + (opos.y - s.pos.y)) -
		((1.0 + (s.k * s.k)) * s.axis.y * m);
	nor.z = ((ray.z * s.t) + (opos.z - s.pos.z)) -
		((1.0 + (s.k * s.k)) * s.axis.z * m);
	vec_normalize(&nor);
	return (nor);
}

double			getdist_cone(t_cone *s, t_vec ray, t_vec opos, int normal)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = vec_dot(ray, ray) - (1.0 + (s->k * s->k)) *
		(vec_dot(ray, s->axis) * vec_dot(ray, s->axis));
	b = 2.0 * (vec_dot(ray, vec_sub(opos, s->pos))
		- (1.0 + (s->k * s->k)) * (vec_dot(ray, s->axis)
			* vec_dot(vec_sub(opos, s->pos), s->axis)));
	c = vec_dot(vec_sub(opos, s->pos), vec_sub(opos, s->pos))
		- (1.0 + (s->k * s->k)) * (vec_dot(vec_sub(opos, s->pos), s->axis)
		* vec_dot(vec_sub(opos, s->pos), s->axis));
	d = (b * b) - (4 * a * c);
	if (d >= 0.0)
	{
		s->t = (-b + sqrt(d)) / (2.0 * a);
		if ((-b - sqrt(d)) / (2.0 * a) < s->t)
			s->t = (-b - sqrt(d)) / (2.0 * a);
		if (normal)
			s->normal = set_normal(*s, ray, opos);
	}
	else
		return (-1.0);
	return (s->t);
}
