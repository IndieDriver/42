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
	//map->env.img = mlx_new_image(map->env.mlx, 640, 480);
	draw_iso(map->env, map->grid, map->height, map->width);
	return (0);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}
/*
void	print_grid(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j].z == 10)
				printf(" %d",map->grid[i][j].z);
			else
				printf("  %d",map->grid[i][j].z);
			j++;
		}
	printf("\n");
	i++;
	}
}
*/

int		main(int argc, char **argv)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	printf("adress before: %p\n", e.mlx);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "42");
	if (argc != 2)
		ft_error();
	else
	{
		if (!(map = get_map(argv[1])))
			ft_error();
		map->env = e;
		printf("grid[3][3]: %d,height: %d, width: %d\n",
		map->grid[0][0].z,map->height, map->width);
		//print_grid(map);
		mlx_expose_hook(e.win, expose_hook, map);
	}

	printf("after after: %p\n",e.mlx);
	mlx_loop(e.mlx);
	printf("after mlx_loop\n");
	sleep(5);
	if (argc == 1)
		argv[0] = NULL;
	return (0);
}
