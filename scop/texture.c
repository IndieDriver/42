/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 13:31:16 by amathias          #+#    #+#             */
/*   Updated: 2016/09/30 13:33:39 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_uv_array(t_map *map)
{
	t_vec2	*uv_array;
	int		i;

	i = 0;
	uv_array = (t_vec2*)malloc(sizeof(t_vec2) * map->nb_vertex);
	while (i < map->nb_vertex)
	{
		uv_array[i].x = fmod(map->vertex_array[i].z, 256);
		uv_array[i].y = fmod(map->vertex_array[i].y, 256);
		i++;
	}
	map->uv_array = uv_array;
}
