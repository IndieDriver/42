/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 13:31:16 by amathias          #+#    #+#             */
/*   Updated: 2016/09/30 13:33:39 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec4	get_normal_tri(t_vec4 pt1, t_vec4 pt2, t_vec4 pt3)
{
	t_vec4 nor;

	nor = vec_cross(vec_sub(pt2, pt1), vec_sub(pt3, pt1));
	vec_normalize(&nor);
	return (nor);
}

void	add_normal(t_map *map, t_vec4 normal, int indice_index)
{
	t_vec4 tmp;

	vec_normalize(&normal);
	tmp = vec3tovec4(map->normal_array[map->indice_array[indice_index]]);
	tmp = vec_add(normal, tmp);
	vec_normalize(&tmp);
	map->normal_array[map->indice_array[indice_index]].x = tmp.x;
	map->normal_array[map->indice_array[indice_index]].y = tmp.y;
	map->normal_array[map->indice_array[indice_index]].z = tmp.z;
}

t_vec4	get_normal(t_map *map, int indice_index)
{
	t_vec3 pt1;
	t_vec3 pt2;
	t_vec3 pt3;
	t_vec4 normal;

	pt1 = map->vertex_array[map->indice_array[indice_index]];
	pt2 = map->vertex_array[map->indice_array[indice_index + 1]];
	pt3 = map->vertex_array[map->indice_array[indice_index + 2]];
	normal = get_normal_tri(vec3tovec4(pt1), vec3tovec4(pt2), vec3tovec4(pt3));
	return (normal);
}

void	get_shared_normal(t_map *map)
{
	t_vec4	nor;
	int		i;

	i = 0;
	nor = get_vec4(0.0f, 0.0f, 0.0f, 0.0f);
	while (i < map->nb_indice)
	{
		nor = get_normal(map, i);
		vec_normalize(&nor);
		add_normal(map, nor, i);
		add_normal(map, nor, i + 1);
		add_normal(map, nor, i + 2);
		i += 3;
	}
	printf("i: %d\n", i);
}

void	set_normal_array(t_map *map)
{
	t_vec3	*normal_array;
	t_vec2	*uv_array;
	int		i;

	i = 0;
	normal_array = (t_vec3*)malloc(sizeof(t_vec3) * map->nb_vertex);
	uv_array = (t_vec2*)malloc(sizeof(t_vec2) * map->nb_vertex);
	while (i < map->nb_vertex)
	{
		normal_array[i].x = 0.0f;
		normal_array[i].y = 0.0f;
		normal_array[i].z = 0.0f;
		uv_array[i].x = 0.0f;
		uv_array[i].y = 0.0f;
		i++;
	}
	map->normal_array = normal_array;
	map->uv_array = uv_array;
	get_shared_normal(map);
}
