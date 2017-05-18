/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_reconstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 19:35:16 by amathias          #+#    #+#             */
/*   Updated: 2016/08/21 16:02:49 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void	copy_vertex_list(t_obj *obj, t_vec3 *vertex_array)
{
	t_list	*vertex_lst;
	t_vec4	*vertex;
	int		i;

	i = 0;
	vertex_lst = obj->vertex;
	while (vertex_lst)
	{
		vertex = vertex_lst->content;
		vertex_array[i].x = vertex->x;
		vertex_array[i].y = vertex->y;
		vertex_array[i].z = vertex->z;
		vertex_lst = vertex_lst->next;
		i++;
	}
}

static void	add_quad_indices(t_vec4 *indice, unsigned int *indice_array, int *index)
{
	indice_array[*index] = (unsigned int)indice->x - 1;
	*index += 1;
	indice_array[*index] = (unsigned int)indice->z - 1;
	*index += 1;
	indice_array[*index] = (unsigned int)indice->w - 1;
	*index += 1;
}

static void	copy_indice_list(t_obj *obj, unsigned int *indice_array)
{
	t_list	*indice_lst;
	t_vec4	*indice;
	int		i;

	i = 0;
	indice_lst = obj->tri;
	while (indice_lst)
	{
		indice = indice_lst->content;
		indice_array[i] = (unsigned int)indice->x - 1;
		i++;
		indice_array[i] = (unsigned int)indice->y - 1;
		i++;
		indice_array[i] = (unsigned int)indice->z - 1;
		i++;
		if ((int)indice->w != -1)
			add_quad_indices(indice, indice_array, &i);
		indice_lst = indice_lst->next;
	}
}

void		obj_reconstruct_indice(t_obj *obj, t_map *map)
{
	t_vec3			*vertex_array;
	unsigned int	*indice_array;
	int				nb_vertex;
	int				nb_tri;

	nb_vertex = count_vertex(obj->vertex);
	nb_tri = count_tri(obj->tri, nb_vertex);
	vertex_array = (t_vec3*)malloc(sizeof(t_vec3) * (nb_vertex));
	copy_vertex_list(obj, vertex_array);
	indice_array = (unsigned int*)malloc(sizeof(float) * nb_tri);
	copy_indice_list(obj, indice_array);
	map->nb_vertex = nb_vertex;
	map->vertex_array = vertex_array;
	map->nb_indice = nb_tri;
	map->indice_array = indice_array;
}
