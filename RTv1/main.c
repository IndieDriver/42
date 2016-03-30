/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/03/30 15:57:27 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw(t_map *map)
{
	map->img.img = mlx_new_image(map->env.mlx, map->scene.w, map->scene.h);
	map->img.data = mlx_get_data_addr(map->img.img, &(map->img.bpp),
			&(map->img.size_line), &(map->img.endian));
	init_image(map, 0x000000);
	raytracer(map);
	mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0, 0);
	mlx_destroy_image(map->env.mlx, map->img.img);
}

void	ft_error(t_map *map, int w)
{
	if (w)
		mlx_destroy_window(map->env.mlx, map->env.win);
	if (w < 0)
		free(map);
	exit(0);
}

int		main(int arc, char **arv)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		ft_error(map, -1);
	if (arc == 2)
		parse_file(map, arv[1]);
	else
		ft_error(map, 0);
	if (map->scene.h <= 0 || map->scene.w <= 0
			|| map->scene.w > 2400 || map->scene.h > 1200)
		ft_error(map, 0);
	if (!(e.win = mlx_new_window(e.mlx, map->scene.w, map->scene.h, "RTv1")))
		ft_error(map, 0);
	map->env = e;
	mlx_key_hook(e.win, key_hook, map);
	mlx_hook(e.win, 17, (1L << 17), red_cross, map);
	mlx_expose_hook(e.win, expose_hook, map);
	mlx_loop(e.mlx);
	return (0);
}
