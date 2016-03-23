/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 14:16:51 by amathias          #+#    #+#             */
/*   Updated: 2016/03/23 17:57:39 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_diffuse(void *shape, t_vec light, int color)
{
	t_vec		nor;
	double		angle;
	int			c;
	t_sphere	*sph;

	sph = shape;
	nor = sph->normal;
	angle = fmax(0.0, vec_dot(light, nor));
	c = col_mul(color, angle);
	return (c);
}
