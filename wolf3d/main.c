/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/03/21 13:17:54 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw(t_map *map)
{
	t_args *arg;

	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	if (map->multithread)
		multi_thread(map, ray);
	else
	{
		arg = init_thread(map, get_pos(0, 0), get_pos(WIDTH, 0));
		ray(arg);
		free(arg);
	}
	if (map->pause)
		pause_on(map);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	if (map->pause)
		mlx_string_put(map->env.mlx, map->env.win,
				(WIDTH / 2) - 24, (HEIGHT / 2) - 10, 0xffffff, "PAUSE");
	mlx_destroy_image(map->env.mlx, map->img.img);
}

void	init_map(t_map *map)
{
	map->grid = get_grid(map, "map");
	if (map->width != 16 || map->height != 30)
		exit(0);
	map->tex = init_tex_array(2);
	map->multithread = 1;
	map->pause = 0;
	map->pos.x = 24.5;
	map->pos.y = 7.5;
	map->cvec.x = 0.0;
	map->cvec.y = 0.66;
	map->dirvec.x = -1.0;
	map->dirvec.y = 0.0;
	init_key(map);
}

int		main(void)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Wolf3d");
	map = (t_map*)malloc(sizeof(t_map));
	map->env = e;
	system("afplay assets/wolf.mp3&");
	init_map(map);
	mlx_key_hook(e.win, key_hook, map);
	mlx_hook(e.win, 2, (1L << 0), key_press, map);
	mlx_loop_hook(e.mlx, loop_hook, map);
	mlx_expose_hook(e.win, expose_hook, map);
	mlx_loop(e.mlx);
	return (0);
}
