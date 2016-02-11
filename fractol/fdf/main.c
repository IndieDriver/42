/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:17:52 by amathias          #+#    #+#             */
/*   Updated: 2016/02/11 17:44:21 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		get_z_offset(t_map *map)
{
	int zmin;
	int zmax;
	int i;
	int j;
	int rst;

	i = 0;
	zmin = 0;
	zmax = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			zmin = map->grid[i][j].z < zmin ? map->grid[i][j].z : zmin;
			zmax = map->grid[i][j].z > zmax ? map->grid[i][j].z : zmax;
			j++;
		}
		i++;
	}
	rst = 42 - abs(zmax - zmin);
	return (rst = rst <= 0 ? 5 : rst);
}

void	draw_fdf(t_map *map)
{
	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	init_image(map, 0x000000);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	draw_iso(map, map->grid, HEIGHT, WIDTH);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	mlx_destroy_image(map->env.mlx, map->img.img);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
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
			//map->grid[i][j].x *= WIDTH / 10;
			//map->grid[i][j].y *= WIDTH / 10;
			map->grid[i][j].x -= map->grid[i][j].z * map->zoffset;
			map->grid[i][j].y -= map->grid[i][j].z * map->zoffset;
			map->grid[i][j] = convertcord(map->grid[i][j]);
			j++;
		}
		i++;
	}
}

int		fdf_init(t_map *map)
{
	map->zoffset = get_z_offset(map);
	shift_grid(map);
	adapt_grid(map);
	draw_fdf(map);
	return (0);
}
