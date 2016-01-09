/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:17:52 by amathias          #+#    #+#             */
/*   Updated: 2016/01/09 16:10:50 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
void	draw(void *mlx, void *win)
{
	int x;
	int y;
	t_point point;

	y = 50;
	while (y < 300)
	{
		x = 50;
		while (x < 300)
		{
			point = convertcord(x, y);
			mlx_pixel_put(mlx, win, point.x, point.y, 0xFF0000);
			x += 10;
		}
		y++;
	}
	x = 50;
	while (x < 300)
	{
		y = 50;
		while (y < 300)
		{
			point = convertcord(x, y);
			mlx_pixel_put(mlx, win, point.x, point.y, 0x0033FF);
			y += 10;
		}
		x++;
	}
}
*/

int		expose_hook(t_env *e)
{
	int grid[4][4] = { {0,0,0,0} , {0,42,42,0} , {0,42,42,0} , {0,0,0,0} };
	t_point **pointgrid = init_grid(grid, 4, 4, 50);
	draw_iso(*e, pointgrid, 4, 4);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "42");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	sleep(5);
	if (argc == 1)
		argv[0] = NULL;
	return (0);
}
