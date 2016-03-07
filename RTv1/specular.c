/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:45 by amathias          #+#    #+#             */
/*   Updated: 2016/03/07 16:15:06 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_reflection(t_map *map, t_vec normal,
		t_vec light, int color, t_vec inter, double refl)
{
	t_vec	r;
	int		color;
	double	s;
	t_sphere *shape;

	color = 0x000000;
	if (refl > 0.0)
	{
		r.x = 2.0 * vec_dotproduct(normal, light) * normal.x - light.x;
		r.y = 2.0 * vec_dotproduct(normal, light) * normal.y - light.y;
		r.z = 2.0 * vec_dotproduct(normal, light) * normal.z - light.z;
		shape = (t_sphere*)iter(map, r, inter);
		if (shape)
			return (shape->color);
	}
	return (0);
}
