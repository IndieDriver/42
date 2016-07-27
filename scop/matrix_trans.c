/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 11:01:37 by amathias          #+#    #+#             */
/*   Updated: 2016/07/27 11:43:17 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_translation_matrix(t_mat4 mat, float x, float y, float z)
{
	ft_bzero(mat, sizeof(t_mat4));
	mat[0] = 1.0f;
	mat[5] = 1.0f;
	mat[10] = 1.0f;
	mat[15] = 1.0f;
	mat[12] = x;
	mat[13] = y;
	mat[14] = z;
}

t_vec4	trans_matrix_vec4(t_vec4 pos, t_vec4 trans)
{
	t_mat4	mat;
	
	get_translation_matrix(mat, trans.x, trans.y, trans.z);
	pos = mul_matrix4_vec4(mat, pos);
	return (pos);
}
