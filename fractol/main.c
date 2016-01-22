/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/01/22 13:52:00 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_map *map)
{
	draw(map);
	return (0);
}

int		key_hook(int keycode, t_map *map)
{
	if (keycode == 24)
	{
		printf("map->zoom: %f\n", map->zoom);
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
	//draw_mandelbrot(map, 1000);
	draw_julia(map, 60, map->zoom);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	mlx_destroy_image(map->env.mlx,map->img.img);
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
	map->zoom = 1.0;
	map->pow = 1;
	mlx_key_hook(e.win, key_hook, map);
	mlx_expose_hook(e.win, expose_hook, map);
	mlx_loop(e.mlx);
	if (argc == 1)
		argv[0] = NULL;
	return (0);
}
