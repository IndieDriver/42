/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/05 12:57:01 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		**init_grid(int row, int col)
{
	int i;
	int j;
	int **grid;

	i = 0;
	if ((grid = (int**)malloc(sizeof(int*) * row)) == NULL)
		return (NULL);
	while (i < row)
	{
		if ((grid[i] = (int*)malloc(sizeof(int) * col)) == NULL)
			return(NULL);
		j = 0;
		while (j < col)
		{
			if (j == 0 || j == col - 1 || i == 0 || i == row - 1)
				grid[i][j] = 1;
			else
				grid[i][j] = 0;
			j++;
		}
		i++;
	}
	//grid[2][1] = 0;
	grid[1][7] = 1;
	grid[1][5] = 1;
	grid[2][3] = 1;
	return (grid);
}

void	draw(t_map *map)
{
	map->img.img = mlx_new_image(map->env.mlx, WIDTH, HEIGHT);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	init_image(map, 0x000000);
	ray(map);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	mlx_destroy_image(map->env.mlx,map->img.img);
}
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
			printf(" %d",map->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
int		loop_hook(t_map *map)
{
	move(map);
	rotate(map);	
	return (0);	
}

int		main(int argc, char **argv)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Wolf3d");
	map = (t_map*)malloc(sizeof(t_map));
	map->env = e;
	map->height = 10;
	map->width = 10;
	map->grid = init_grid(map->height, map->width);
	map->pos.x = 6.0;
	map->pos.y = 6.0;
	map->cvec.x = 0.0;
	map->cvec.y = 0.66;
	map->dirvec.x = -1.0;
	map->dirvec.y = 0.0;
	init_key(map);
	print_grid(map);
	mlx_key_hook(e.win, key_hook, map);
	mlx_hook(e.win, 2, (1L<<0), key_press, map);
	mlx_loop_hook(e.mlx, loop_hook, map);
	mlx_expose_hook(e.win, expose_hook, map);
	mlx_loop(e.mlx);
	if (argc == 2)
		argv[0] = NULL;
	return (0);
}
