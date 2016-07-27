/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 17:25:29 by amathias          #+#    #+#             */
/*   Updated: 2016/07/24 19:16:02 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec4	vec_scale(t_vec4 v1, float fact)
{
	t_vec4 res;

	res.x = v1.x * fact;
	res.y = v1.y * fact;
	res.z = v1.z * fact;
	return (res);
}

void	vec_normalize(t_vec4 *v1)
{
	double	fact;
	double	len;

	if ((len = vec_len(*v1)) == 0)
		len = 0.001;
	fact = 1.0f / len;
	v1->x *= fact;
	v1->y *= fact;
	v1->z *= fact;
}

double	dot(t_vec4 v1, t_vec4 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	dis_point(t_vec4 pt1, t_vec4 pt2)
{
	return (sqrt((pt2.x - pt1.x) * (pt2.x - pt1.x) + (pt2.y - pt1.y) *
				(pt2.y - pt1.y) + (pt2.z - pt1.z) * (pt2.z - pt1.z)));
}

t_vec4	neg_vec(t_vec4 vec)
{
	vec.x *= -1;
	vec.y *= -1;
	vec.z *= -1;
	return (vec);
}
