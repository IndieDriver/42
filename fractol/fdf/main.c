/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:17:52 by amathias          #+#    #+#             */
/*   Updated: 2016/02/18 16:11:02 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_fdf(t_map *map)
{
	draw_iso(map, map->grid, HEIGHT, WIDTH);
}

void	shift_grid(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			map->grid[i][j].x -= (WIDTH / 2);
			map->grid[i][j].y -= (HEIGHT / 2);
			map->grid[i][j].x -= map->grid[i][j].z * 3;
			map->grid[i][j].y -= map->grid[i][j].z * 3;
			map->grid[i][j] = convertcord(map->grid[i][j]);
			j++;
		}
		i++;
	}
}

int		fdf_init(t_map *map)
{
	shift_grid(map);
	draw_fdf(map);
	return (0);
}
