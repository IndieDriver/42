/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/01/24 10:38:22 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_map *map)
{
	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	init_image(map, 0x000000);
	//draw_mandelbrot(map, 120);
	draw_julia(map, 60);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	mlx_destroy_image(map->env.mlx,map->img.img);
}

int		main(int argc, char **argv)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Fractol");
	map = (t_map*)malloc(sizeof(t_map));
	map->env = e;
	map->zoom = 1.0;
	map->pow = 1;
	map->c.ima = 0.0;
	map->c.real = 0.0;
	mlx_key_hook(e.win, key_hook, map);
	mlx_hook(e.win, 6, (1L<<6), motion_notify, map);
	mlx_expose_hook(e.win, expose_hook, map);
	mlx_loop(e.mlx);
	if (argc == 1)
		argv[0] = NULL;
	return (0);
}
