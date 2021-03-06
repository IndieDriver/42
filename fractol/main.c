/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/20 16:43:31 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_map *map)
{
	char *str;

	if (map->iso)
		init_grid(map);
	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	draw_fractal(map);
	if (map->iso)
	{
		fdf_init(map);
		free_grid(map);
	}
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	str = ft_itoa(map->max_iter);
	mlx_string_put(map->env.mlx, map->env.win, 10, 10, 0xFFFFFF, str);
	free(str);
	mlx_destroy_image(map->env.mlx, map->img.img);
}

int		get_type(char *line)
{
	if (!ft_strcmp("julia", line))
		return (1);
	else if (!ft_strcmp("mandelbrot", line))
		return (2);
	else if (!ft_strcmp("burning", line))
		return (3);
	else if (!ft_strcmp("rabbit", line))
		return (4);
	else if (!ft_strcmp("siegel", line))
		return (5);
	else
		return (0);
}

int		init_map(t_map *map, char *line)
{
	map->zoom = 1.0;
	map->max_iter = 120;
	map->iso = 0;
	map->mx = 0.0;
	map->my = 0.0;
	map->c.ima = 0.0;
	map->c.real = 0.0;
	if (!(map->type = get_type(line)))
		return (0);
	return (1);
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
			ft_error(2);
		mlx_key_hook(e.win, key_hook, map);
		mlx_hook(e.win, 2, (1L << 0), key_press, map);
		mlx_hook(e.win, 6, (1L << 6), motion_notify, map);
		mlx_loop_hook(e.mlx, loop_hook, map);
		mlx_mouse_hook(e.win, mouse_hook, map);
		mlx_expose_hook(e.win, expose_hook, map);
		mlx_loop(e.mlx);
	}
	else
		ft_error(2);
	return (0);
}
