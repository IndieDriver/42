/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:28:56 by amathias          #+#    #+#             */
/*   Updated: 2016/07/27 15:55:25 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	move(t_map *map)
{	
	if (map->key.up == 1)
		map->rot.x = map->rot.x + (0.1f);
	if (map->key.down == 1)
		map->rot.x = map->rot.x - (0.1f);
	if (map->key.right == 1)
		map->rot.y = map->rot.y + (0.1f);
	if (map->key.left == 1)
		map->rot.y = map->rot.y - (0.1f);
	if (map->key.left || map->key.right || map->key.up || map->key.down)
	{
		apply_trans(map->modelmat4, map->pos, map->rot);
		get_mvp(map->mvpmat4, map->modelmat4, map->viewmat4, map->projmat4);
		draw(map);
	}



	/*
	get_identity_mat4(map->modelmat4);
	if (map->key.up == 1)
		map->pos = vec_add(map->pos, vec_scale(map->cam.dir, 0.1));
	if (map->key.down == 1)
		map->pos = vec_sub(map->pos, vec_scale(map->cam.dir, 0.1));
	if (map->key.right == 1)
		map->pos = vec_add(map->pos, vec_scale(map->cam.right, 0.1));
	if (map->key.left == 1)
		map->pos = vec_sub(map->pos, vec_scale(map->cam.right, 0.1));
	if (map->key.left || map->key.right || map->key.up || map->key.down)
	{
		get_translation_matrix(map->modelmat4,
			map->pos.x, map->pos.y, map->pos.z);
		print_matrix(map->modelmat4);
		//get_viewmatrix(map, map->cam.pos,
		//	get_vec4(0.0f, 0.0f, 0.0f, 0.0f), get_vec4(0.0f, 1.0f, 0.0f, 0.0f));
		draw(map);
	}
		*/	
/*	
	if (map->key.up == 1)
		map->cam.pos = vec_add(map->cam.pos, vec_scale(map->cam.dir, 0.1));
	if (map->key.down == 1)
		map->cam.pos = vec_sub(map->cam.pos, vec_scale(map->cam.dir, 0.1));
	if (map->key.right == 1)
		map->cam.pos = vec_add(map->cam.pos, vec_scale(map->cam.right, 0.1));
	if (map->key.left == 1)
		map->cam.pos = vec_sub(map->cam.pos, vec_scale(map->cam.right, 0.1));
	if (map->key.left || map->key.right || map->key.up || map->key.down)
	{
		get_viewmatrix(map, map->cam.pos,
			get_vec4(0.0f, 0.0f, 0.0f, 0.0f), get_vec4(0.0f, 1.0f, 0.0f, 0.0f));
		draw(map);
	} */
}
