/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:41:56 by amathias          #+#    #+#             */
/*   Updated: 2016/03/16 13:42:38 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	getdist_sph(t_sphere s, t_vec ray, t_vec opos)
{
	double a;
	double b;
	double c;
	double d;
	double t;

	a = vec_dotproduct(ray, ray);
	b = 2.0 * (vec_dotproduct(ray, vec_sub(opos, s.pos)));
	c = (vec_dotproduct(vec_sub(opos, s.pos), vec_sub(opos, s.pos)))
		- s.radius * s.radius;
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

double	getdist_plan(t_plan plan, t_vec ray, t_vec opos)
{
	double	t;

	t = -(((plan.normal.x * (opos.x - plan.pos.x)) +
			(plan.normal.y * (opos.y - plan.pos.y)) +
			(plan.normal.z * (opos.z - plan.pos.z)))
			/ ((plan.normal.x * ray.x) + (plan.normal.y * ray.y)
				+ (plan.normal.z * ray.z)));
	if (t < 0.0)
		return (-1.0);
	return (t);
}
