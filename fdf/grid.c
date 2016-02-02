/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:39:26 by amathias          #+#    #+#             */
/*   Updated: 2016/02/02 10:55:17 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point **copy_grid(t_map *map, t_point **src)
{
	t_point **grid;
	int i;
	int j;

	if (!(grid = (t_point **)malloc(sizeof(t_point*) * map->height)))
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		if (!(grid[i] = (t_point *)malloc(sizeof(t_point) * map->width)))
				return (NULL);
		j = 0;
		while (j < map->width)
		{
			grid[i][j] = src[i][j];
			j++;
		}
		i++;
	}
	return (grid);
}
