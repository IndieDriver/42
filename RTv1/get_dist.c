/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:41:56 by amathias          #+#    #+#             */
/*   Updated: 2016/03/11 15:51:16 by amathias         ###   ########.fr       */
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

	//printf("ray.x: %f| ray.y: %f| ray.z: %f\npos.x: %f| pos.y: %f| pos.z: %f\n", 		ray.x, ray.y, ray.z, opos.x, opos.y, opos.z);
	a = ray.x * ray.x + ray.y * ray.y + ray.z * ray.z;
	b = 2.0 * (ray.x * (opos.x - s.pos.x)
		+ ray.y * (opos.y - s.pos.y)
		+ ray.z * (opos.z - s.pos.z));
	c = (opos.x - s.pos.x) * (opos.x - s.pos.x)
		+ (opos.y - s.pos.y) * (opos.y - s.pos.y)
		+ (opos.z - s.pos.z) * (opos.z - s.pos.z)
		- s.radius * s.radius;
	d = (b * b) - (4 * a * c);
	//printf("d: %f\n", d);
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
	t_vec	nor;
	double	t;

	(void)plan;
	nor.x = 0.0;
	nor.y = 1.0;
	nor.z = 0.0;
	t = -(((nor.x * (opos.x - 0.0)) +
			(nor.y * (opos.y - 0.0)) +
			(nor.z * (opos.z - 0.0)))
			/ ((nor.x * ray.x) + (nor.y * ray.y) + (nor.z * ray.z)));
	if (t < 0.0)
		return (-1.0);
	return (t);
}

/*
double	getdist_cyl(t_cylinder cyl, t_vec ray, t_vec opos)
{
	double a;
	double b;
	double c;
	double d;
	double t;
	t_vec axis;
	double r;

	r = 10.0;
	axis.x = 0.0;
	axis.y = 1.0;
	axis.z = 0.0;
	a = (ray.x * ray.x + ray.z * ray.z);
	b = 2 * (ray.x * (opos.x - cyl.pos.x) + ray.z * (opos.z - cyl.pos.z));
	c = (((opos.x - cyl.pos.x) * (opos.x - cyl.pos.x)) +
		((opos.z - cyl.pos.z) * (opos.z - cyl.pos.z))) - r * r;
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
} */

