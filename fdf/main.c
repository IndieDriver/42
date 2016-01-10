/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:17:52 by amathias          #+#    #+#             */
/*   Updated: 2016/01/10 16:41:44 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_map *map)
{
	map->env.img = mlx_new_image(map->env.mlx, 640, 480);
	draw_iso(map->env, map->map, map->height, map->width);
	return (0);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void 	ft_setup(t_map *map)
{
	map->width = 19;
	map->height = 11;
}
int		main(int argc, char **argv)
{
	t_env e;
	//int fd;
	t_map *map;
	int grid[11][19] = { {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,10,10,0,0,10,10,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,10,10,0,0,10,10,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,10,10,0,0,10,10,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,10,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,10,10,10,10,10,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,10,10,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };
	map = malloc(sizeof(t_map));
	map->map = init_grid(grid,11,19,15);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "42");
	if (argc != 2)
		ft_error();
	else
	{
		ft_setup(map);
		//fd = open(argv[1], O_RDONLY);
		//map = ft_parse(fd, map);
		map->env = e;
		mlx_expose_hook(e.win, expose_hook, map);
	}
	mlx_loop(e.mlx);
	sleep(5);
	if (argc == 1)
		argv[0] = NULL;
	return (0);
}
