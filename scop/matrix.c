/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 10:37:38 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 10:37:34 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	cpy_mat4(t_mat4 src, t_mat4 dest)
{
	int i;

	i = 0;
	while (i < 16)
	{
		dest[i] = src[i];
		i++;
	}
}

void	mat4_mul(t_mat4 result, t_mat4 m1, t_mat4 m2)
{
	float	sum;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			sum = 0.0f;
			while (k < 4)
			{
				sum += (m1[i * 4 + k] * m2[k * 4 + j]);
				k++;
			}
			result[i * 4 + j] = sum;
			j++;
		}
		i++;
	}
}

void	get_identity_mat4(t_mat4 mat)
{
	ft_bzero(mat, sizeof(t_mat4));
	mat[0] = 1.0f;
	mat[5] = 1.0f;
	mat[10] = 1.0f;
	mat[15] = 1.0f;
}

t_vec4	mul_matrix4_vec4(t_mat4 mat, t_vec4 vec4)
{
	t_vec4 out;

	out.x = (mat[0] * vec4.x) + (mat[1] * vec4.y)
				+ (mat[2] * vec4.z) + (mat[3] * vec4.w);
	out.y = (mat[4] * vec4.x) + (mat[5] * vec4.y)
				+ (mat[6] * vec4.z) + (mat[7] * vec4.w);
	out.z = (mat[8] * vec4.x) + (mat[9] * vec4.y)
				+ (mat[10] * vec4.z) + (mat[11] * vec4.w);
	out.w = (mat[12] * vec4.x) + (mat[13] * vec4.y)
				+ (mat[14] * vec4.z) + (mat[15] * vec4.w);
	return (out);
}
