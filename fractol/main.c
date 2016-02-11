/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/11 17:15:49 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_map *map)
{
	int *color_array;

	init_grid(map);
	color_array = NULL;
	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	init_image(map, 0x000000);
	if (map->type == 1)
		draw_julia(map, 60, 2);
	else if (map->type == 2)
		draw_mandelbrot(map, 60, color_array, 2);
	else if (map->type == 3)
		draw_burning(map, 60, color_array, 2);
	if (map->iso)
		fdf_init(map);
	else
	{
		mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
		mlx_destroy_image(map->env.mlx, map->img.img);
	}
}

int		init_map(t_map *map, char *line)
{
	map->zoom = 1.0;
	map->iso = 1;
	map->pow = 1;
	map->mx = 0.0;
	map->my = 0.0;
	map->c.ima = 0.0;
	map->c.real = 0.0;
	if (!ft_strcmp("julia", line))
		map->type = 1;
	else if (!ft_strcmp("mandelbrot", line))
		map->type = 2;
	else if (!ft_strcmp("burning", line))
		map->type = 3;
	else
		return (0);
	return (1);
}

void	init_key(t_map *map)
{
	map->key.up = 0;
	map->key.down = 0;
	map->key.left = 0;
	map->key.right = 0;
	map->key.mup = 0;
	map->key.mdown = 0;
}

int		main(int argc, char **argv)
{
	t_env e;
	t_map *map;

	if (argc == 2)
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Fractol");
		map = (t_map*)malloc(sizeof(t_map));
		map->env = e;
		init_key(map);
		if (!init_map(map, argv[1]))
		{
			ft_putstr("Invalid arg\n./fractol <julia|mandelbrot|burning>\n");
			exit(0);
		}
		mlx_key_hook(e.win, key_hook, map);
		mlx_hook(e.win, 6, (1L << 6), motion_notify, map);
		mlx_hook(e.win, 2, (1L << 0), key_press, map);
		mlx_loop_hook(e.mlx, loop_hook, map);
		mlx_expose_hook(e.win, expose_hook, map);
		mlx_loop(e.mlx);
	}
	else
		ft_putstr("Invalid arg\n./fractol <julia|mandelbrot|burning>\n");
	return (0);
}
