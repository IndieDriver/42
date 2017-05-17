/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 18:49:05 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 11:42:48 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	get_normalmat(t_mat4 out, t_mat4 m, t_mat4 v)
{
	t_mat4	tmp;
	int		i;
	int		j;

	ft_bzero(tmp, sizeof(t_mat4));
	ft_bzero(out, sizeof(t_mat4));
	mat4_mul(tmp, m, v);
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			out[i * 4 + j] = tmp[i * 4 + j];
			j++;
		}
		i++;
	}
}

void	get_mvp(t_mat4 out, t_mat4 m, t_mat4 v, t_mat4 p)
{
	t_mat4 tmp;

	ft_bzero(tmp, sizeof(t_mat4));
	mat4_mul(tmp, m, v);
	mat4_mul(out, tmp, p);
}

void	apply_trans(t_mat4 in, t_vec4 pos, t_vec4 rot)
{
	t_mat4	mtran;
	t_mat4	mrot;

	ft_bzero(in, sizeof(t_mat4));
	ft_bzero(mtran, sizeof(t_mat4));
	ft_bzero(mrot, sizeof(t_mat4));
	get_rot_matrix(mrot, fmod(rot.x, 360.0f), fmod(rot.y, 360.0f),
		fmod(rot.z, 360.0f));
	get_translation_matrix(mtran, pos.x, pos.y, pos.z);
	mat4_mul(in, mrot, mtran);
}

void	get_projmatrix(t_mat4 mat, float fov, float ratio)
{
	float	near;
	float	far;
	float	frustum;
	float	tan_half_fov;

	near = 0.1f;
	far = 100.0f;
	frustum = near - far;
	tan_half_fov = tanf(fov / 2.0f);
	get_identity_mat4(mat);
	mat[0] = 1.0f / (ratio / tan_half_fov);
	mat[5] = 1.0f / tan_half_fov;
	mat[10] = (far + near) / frustum;
	mat[11] = -1.0f;
	mat[14] = 2.0f * (far * near) / frustum;
	mat[15] = 0.0f;
}

void	get_viewmatrix(t_map *map, t_vec4 pos, t_vec4 center, t_vec4 up)
{
	t_vec4	u;

	map->cam.dir = vec_sub(center, pos);
	vec_normalize(&map->cam.dir);
	u = up;
	vec_normalize(&u);
	map->cam.right = vec_cross(map->cam.dir, u);
	vec_normalize(&map->cam.right);
	u = vec_cross(map->cam.right, map->cam.dir);
	get_identity_mat4(map->viewmat4);
	map->viewmat4[0] = map->cam.right.x;
	map->viewmat4[4] = map->cam.right.y;
	map->viewmat4[8] = map->cam.right.z;
	map->viewmat4[1] = u.x;
	map->viewmat4[5] = u.y;
	map->viewmat4[9] = u.z;
	map->viewmat4[2] = -map->cam.dir.x;
	map->viewmat4[6] = -map->cam.dir.y;
	map->viewmat4[10] = -map->cam.dir.z;
	map->viewmat4[12] = -dot(map->cam.right, pos);
	map->viewmat4[13] = -dot(u, pos);
	map->viewmat4[14] = dot(map->cam.dir, pos);
}
