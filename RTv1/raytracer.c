/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/02/28 13:52:19 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ray(t_map *map, int x, int y)
{
	map->scene.rayvec.x = (x - (map->scene.w / 2)) * 1;
	map->scene.rayvec.y = (y - (map->scene.h / 2)) * 1;
	map->scene.rayvec.z = -(map->scene.w / (2 * tan((45 / 2) * M_PI / 180.0)));
}

void	raytracer(t_map *map)
{
	int x;
	int y;

	y = 0;
	map->scene.sphere[0].radius = 25.0;
	map->scene.sphere[1].radius = 25.0;
	while (y < map->scene.h)
	{
		x = 0;
		while (x < map->scene.w)
		{
			ray(map, x, y);	
			iter(map, x, y);
			x++;
		}
		y++;
	}
	printf("done\n");
}
