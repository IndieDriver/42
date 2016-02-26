/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:58:25 by amathias          #+#    #+#             */
/*   Updated: 2016/02/26 03:52:23 by amathias         ###   ########.fr       */
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
	mlx_destroy_image(map->env.mlx,map->img.img);
}

void	init_map(t_map *map)
{
	init_key(map);	
}

int		main(int arc, char **arv)
{
	t_env e;
	t_map *map;

	e.mlx = mlx_init();
	map = (t_map*)malloc(sizeof(t_map));
	init_map(map);
	if (arc == 2)
		parse_file(map, arv[1]);
	e.win = mlx_new_window(e.mlx, map->scene.w, map->scene.h, "RTv1");
	map->env = e;
	mlx_key_hook(e.win, key_hook, map);
	//mlx_hook(e.win, 2, (1L << 0), key_press, map);
	//mlx_loop_hook(e.mlx, loop_hook, map);
	mlx_expose_hook(e.win, expose_hook, map);
	mlx_loop(e.mlx);
	return (0);
}
