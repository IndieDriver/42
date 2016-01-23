/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/01/23 15:54:52 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_map *map)
{
	draw(map);
	return (0);
}

int		motion_notify(int x, int y, t_map *map)
{
	if (x > 0 && y > 0 && x < WIDTH && y < WIDTH)
	{
		map->c.real = 1.5 * (x - (WIDTH / 2)) / (WIDTH * map->zoom / 2);
		map->c.ima = 1.5 * (y - (HEIGHT / 2)) / (HEIGHT * map->zoom / 2);
		draw(map);
	}
	return (0);
}

int		key_hook(int keycode, t_map *map)
{
	if (keycode == 24)
	{
		map->pow++;
		map->zoom *= pow(1.001, map->pow);
		draw(map);
	}
	if (keycode == 27)
	{
		map->pow = map->pow < 1 ? 1 : map->pow - 1;
		map->zoom = map->zoom < 1 ? 1 : map->zoom / pow(1.001, map->pow);
		draw(map);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(map->env.mlx, map->env.win);
		exit(0);
	}
	return (0);
}

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
