/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:40:10 by amathias          #+#    #+#             */
/*   Updated: 2016/02/17 12:55:08 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_grid(t_map *map)
{
	int i;

	i = 0;
	while (i < HEIGHT)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	init_grid(t_map *map)
{
	int		i;
	int		j;
	t_point	**grid;

	i = 0;
	if (!(grid = (t_point**)malloc(sizeof(t_point*) * HEIGHT)))
		return ;
	while (i < HEIGHT)
	{
		j = 0;
		if (!(grid[i] = (t_point*)malloc(sizeof(t_point) * WIDTH)))
			return ;
		while (j < WIDTH)
		{
			grid[i][j].x = j;
			grid[i][j].y = i;
			grid[i][j].z = 0;
			j++;
		}
		i++;
	}
	map->grid = grid;
}
