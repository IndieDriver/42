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

void	add_vertex_in_list(float *tri_list, int *index, t_vec3 *vertex)
{
	tri_list[*index] = vertex->x;
	*index += 1;
	tri_list[*index] = vertex->y;
	*index += 1;
	tri_list[*index] = vertex->z;
	*index += 1;
}

void	insert_quad(t_obj *obj, t_vec4 *vec, float *tri_list, int *index)
{
	t_list	*lst_vertex;
	t_vec3	*vertex;

	lst_vertex = ft_lstat(obj->vertex, (int)vec->x - 1);
	vertex = (t_vec3*)lst_vertex->content;
	add_vertex_in_list(tri_list, index, vertex);
	lst_vertex = ft_lstat(obj->vertex, (int)vec->z - 1);
	vertex = (t_vec3*)lst_vertex->content;
	add_vertex_in_list(tri_list, index, vertex);
	lst_vertex = ft_lstat(obj->vertex, (int)vec->w - 1);
	vertex = (t_vec3*)lst_vertex->content;
	add_vertex_in_list(tri_list, index, vertex);
}

void	insert_vertex(t_obj *obj, t_vec4 *vec, float *tri_list, int *index)
{
	t_list	*lst_vertex;
	t_vec3	*vertex;

	//check for quad there
	//printf("%d %d %d %d\n", (int)vec->x, (int)vec->y, (int)vec->z,
	//	(int)vec->w);
	lst_vertex = ft_lstat(obj->vertex, (int)vec->x - 1);
	vertex = (t_vec3*)lst_vertex->content;
	//printf("%f %f %f\n", vertex->x, vertex->y, vertex->z);
	//printf("%d\n", *index);
	add_vertex_in_list(tri_list, index, vertex);
	lst_vertex = ft_lstat(obj->vertex, (int)vec->y - 1);
	vertex = (t_vec3*)lst_vertex->content;
	add_vertex_in_list(tri_list, index, vertex);
	lst_vertex = ft_lstat(obj->vertex, (int)vec->z - 1);
	vertex = (t_vec3*)lst_vertex->content;
	add_vertex_in_list(tri_list, index, vertex);
	if ((int)vec->w != -1)
		insert_quad(obj, vec, tri_list, index);
}

void	build_list(t_obj *obj, float *tri_list)
{
	t_list	*lst_tri;
	t_vec4	*vec;
	int		i;

	i = 0;
	lst_tri = obj->tri;
	while (lst_tri)
	{
		vec = (t_vec4*)lst_tri->content;
		insert_vertex(obj, vec, tri_list, &i);
		lst_tri = lst_tri->next;
	}
}

float	*obj_reconstruct(t_obj *obj, t_map *map)
{
	float	*tri_list;
	int		max_vertex;
	int		nb_tri;
	int		i;

	max_vertex = count_vertex(obj->vertex);
	nb_tri = count_tri(obj->tri, max_vertex);
	printf("v %d\n", max_vertex);
	printf("f %d\n", nb_tri);
	tri_list = (float*)malloc(sizeof(float) * (nb_tri * 3));
	build_list(obj, tri_list);
	i = -1;
	/*while (i < nb_tri * 3)
	{
		printf("%f ", tri_list[i]);
		if ((i + 1) % 3 == 0)
			printf("\n");
		i++;
	} */
	map->nb_tri = nb_tri;
	return (tri_list);
}
