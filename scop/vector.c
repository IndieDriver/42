/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 16:04:55 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 14:49:53 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec3	get_vec3(float x, float y, float z)
{
	t_vec3 vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec4	vec3tovec4(t_vec3 vec3)
{
	t_vec4 vec;

	vec.x = vec3.x;
	vec.y = vec3.y;
	vec.z = vec3.z;
	vec.w = 0.0f;
	return (vec);
}

t_vec4	get_vec4(float x, float y, float z, float w)
{
	t_vec4 vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}

int		vec4cmp(t_vec4 v1, t_vec4 v2)
{
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return (1);
	return (0);
}

t_vec4	neg_vec4(t_vec4 vec)
{
    vec.x *= -1;
    vec.y *= -1;
    vec.z *= -1;
    vec.w *= -1;
    return (vec);
}
