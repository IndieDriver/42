/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/01/22 11:25:01 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_map *map)
{
	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	init_image(map, 0x000000);
	draw_mandelbrot(map, 1000);
	//draw_julia(map, 120);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	mlx_destroy_image(map->env.mlx,map->img.img);
	return (0);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "42");
	map = (t_map*)malloc(sizeof(t_map));
	map->env = e;
	mlx_expose_hook(e.win, expose_hook, map);
	mlx_loop(e.mlx);
	sleep(5);
	if (argc == 1)
		argv[0] = NULL;
	return (0);
}
