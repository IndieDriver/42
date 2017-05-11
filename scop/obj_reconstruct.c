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

int		count_tri(t_list *elem, int max_vertex)
{
	t_vec4	*vec;
	int		i;

	i = 0;
	while (elem)
	{
		vec = (t_vec4*)elem->content;
		if ((int)vec->x > max_vertex
			|| (int)vec->y > max_vertex || (int)vec->z > max_vertex)
		{
			ft_putstr("Invalid f value (value > max_vertex)\n");
			exit(0);
		}
		i = vec->w != -1.0f ? i + 6 : i + 3;
		elem = elem->next;
	}
	return (i);
}

int		count_vertex(t_list *elem)
{
	int i;

	i = 0;
	while (elem)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}

void 	copy_vertex_list(t_obj *obj, float *vertex_array)
{
	t_list	*vertex_lst;
	t_vec4	*vertex;
	int		i;

	i = 0;
	vertex_lst = obj->vertex;
	while (vertex_lst)
	{
		vertex = vertex_lst->content;
		vertex_array[i] = vertex->x;
		i++;
		vertex_array[i] = vertex->y;
		i++;
		vertex_array[i] = vertex->z;
		i++;
		vertex_lst = vertex_lst->next;
	}
}

void	add_quad_indices(t_vec4 *indice, unsigned int *indice_array, int *index)
{
	indice_array[*index] = indice->x - 1;
	*index += 1;
	indice_array[*index] = indice->z - 1;
	*index += 1;
	indice_array[*index] = indice->w - 1;
	*index += 1;
}

void	copy_indice_list(t_obj *obj, unsigned int *indice_array)
{
	t_list	*indice_lst;
	t_vec4	*indice;
	int		i;

	i = 0;
	indice_lst = obj->tri;
	while (indice_lst)
	{
		indice = indice_lst->content;
		indice_array[i] = indice->x - 1;
		i++;
		indice_array[i] = indice->y - 1;
		i++;
		indice_array[i] = indice->z - 1;
		i++;
		if ((int)indice->w != -1)
			add_quad_indices(indice, indice_array, &i);
		indice_lst = indice_lst->next;
	}
}

void	obj_reconstruct(t_obj *obj, t_map *map)
{
	float			*vertex_array;
	unsigned int	*indice_array;
	int				nb_vertex;
	int				nb_tri;

	nb_vertex = count_vertex(obj->vertex);
	nb_tri = count_tri(obj->tri, nb_vertex);
	printf("v %d\n", nb_vertex);
	printf("f %d\n", nb_tri);
	vertex_array = (float*)malloc(sizeof(float) * (nb_vertex * 3));
	copy_vertex_list(obj, vertex_array);
	indice_array = (unsigned int*)malloc(sizeof(float) * nb_tri);
	copy_indice_list(obj, indice_array);
	map->nb_vertex = nb_vertex;
	map->vertex_array = vertex_array;
	map->nb_indice = nb_tri;
	map->indice_array = indice_array;
}
