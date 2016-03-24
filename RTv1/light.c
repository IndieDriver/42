/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 14:16:51 by amathias          #+#    #+#             */
/*   Updated: 2016/03/24 17:34:22 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		get_spec(void *shape, t_vec light, t_vec eye)
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
		dot = pow(dot, 42.0);
		return (dot);
	}
	return (0);
}

double		get_diffuse(void *shape, t_vec light)
{
	t_vec		nor;
	double		ldif;
	t_sphere	*sph;

	sph = shape;
	nor = sph->normal;
	ldif = fmax(0.0, vec_dot(light, nor));;
	return (ldif);
}
