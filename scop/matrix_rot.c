/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 12:08:50 by amathias          #+#    #+#             */
/*   Updated: 2016/07/27 14:07:17 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_rot_matrix(t_mat4 mat, float rot_x, float rot_y, float rot_z)
{
	float a;
	float b;
	float c;
	float d;
	float e;

	//ft_bzero(mat, sizeof(t_mat4));
	get_identity_mat4(mat);
	a = cos(rot_x);
	b = sin(rot_x);
	c = cos(rot_y);
	d = sin(rot_y);
	e = cos(rot_z);
	mat[0] = c * e;
	mat[1] = -c * sin(rot_z);
	mat[2] = d;
	mat[4] = (b * d) * e + a * sin(rot_z);
	mat[5] = -(b * d) * sin(rot_z) + a * e;
	mat[6] = -b * c;
	mat[8] = -(a * d) * e + b * sin(rot_z);
	mat[9] = (a * d) * sin(rot_z) + b * e;
	mat[10] = a * c;
	mat[15] = 1.0f;
}

t_vec4	rot_matrix_vec4(t_vec4 pos, t_vec4 trans)
{
	t_mat4	mat;

	ft_bzero(mat, sizeof(t_mat4));
	get_rot_matrix(mat, trans.x, trans.y, trans.z);
	pos = mul_matrix4_vec4(mat, pos);
	return (pos);
}
