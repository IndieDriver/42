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

int		count_tri(t_list *elem, int max_ver)
{
	t_vec4	*v;
	int		i;

	i = 0;
	while (elem)
	{
		v = (t_vec4*)elem->content;
		if ((int)v->x > max_ver || (int)v->y > max_ver || (int)v->z > max_ver ||
				(int)v->w > max_ver || (int)v->x <= 0 || (int)v->y <= 0
				|| (int)v->z <= 0 || ((int)v->w != -1.0f && (int)v->w <= 0))
		{
			ft_putstr("Invalid f value (value > max_vertex or value <= 0)\n");
			exit(0);
		}
		i = v->w != -1.0f ? i + 6 : i + 3;
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

void	duplicate_vertex_list(t_map *map, t_vec3 *vertex_array)
{
	int i;

	i = 0;
	while (i < map->nb_indice)
	{
		vertex_array[i] = map->vertex_array[map->indice_array[i]];
		i++;
	}
}

void	obj_reconstruct(t_map *map)
{
	t_vec3			*vertex_array;

	vertex_array = (t_vec3*)malloc(sizeof(t_vec3) * (map->nb_indice));
	duplicate_vertex_list(map, vertex_array);
	map->nb_vertex = map->nb_indice;
	free(map->vertex_array);
	map->vertex_array = vertex_array;
	map->nb_indice = -1;
	free(map->indice_array);
	map->indice_array = NULL;
}
