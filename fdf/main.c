/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:17:52 by amathias          #+#    #+#             */
/*   Updated: 2016/02/10 13:59:18 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			zmin = map->grid[i][j].z < zmin ? map->grid[i][j].z : zmin;
			zmax = map->grid[i][j].z > zmax ? map->grid[i][j].z : zmax;
			j++;
		}
		i++;
	}
	rst = 42 - abs(zmax - zmin);
	return (rst = rst <= 0 ? 1 : rst);
}

void	draw(t_map *map)
{
	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	init_image(map, 0x000000);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	draw_iso(map, map->grid, map->height, map->width);
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
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->grid[i][j].x -= (map->width / 2);
			map->grid[i][j].y -= (map->height / 2);
			map->grid[i][j].x *= WIDTH / 10;
			map->grid[i][j].y *= WIDTH / 10;
			map->grid[i][j].x -= map->grid[i][j].z * map->zoffset;
			map->grid[i][j].y -= map->grid[i][j].z * map->zoffset;
			map->grid[i][j] = convertcord(map->grid[i][j]);
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_env e;
	t_map *map;

	if (argc != 2)
		ft_error();
	else
	{
		if (!(map = get_map(argv[1])))
			ft_error();
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "FdF");
		init_key(map);
		map->env = e;
		map->zoffset = get_z_offset(map);
		shift_grid(map);
		adapt_grid(map);
		mlx_key_hook(e.win, key_hook, map);
		mlx_hook(e.win, 2, (1L << 0), key_press, map);
		mlx_loop_hook(e.mlx, loop_hook, map);
		mlx_expose_hook(e.win, expose_hook, map);
		mlx_loop(e.mlx);
		free_map(map);
	}
	return (0);
}
