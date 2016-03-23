/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:45 by amathias          #+#    #+#             */
/*   Updated: 2016/03/23 18:23:44 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_reflected_shape(t_map *map, t_vec ray, t_vec inter, int color)
{
	t_sphere *sh;

	sh = (t_sphere*)iter(map, ray, inter, 0);
	if (sh)
		return (sh->color);
	return (color);
}

int		get_reflection(void *shape, t_vec light, t_vec eye, int color)
{
	t_vec		r;
	t_sphere	*sh;
	t_vec		normal;
	double		dot;

	sh = shape;
	normal = sh->normal;
	vec_normalize(&eye);
	if (vec_dot(light, normal) > 0.0)
	{
		r.x = (light.x + eye.x);
		r.y = (light.y + eye.y);
		r.z = (light.z + eye.z);
		vec_normalize(&r);
		dot = fmax(0.0, vec_dot(r, normal));
		dot = pow(dot, 16.0);
		//printf("dot: %f\n", dot);
		if (dot < 0.0)
			return (color);
		return (col_add_mul(color, 0xFFFFFF, dot));
	}
	return (color);
}
