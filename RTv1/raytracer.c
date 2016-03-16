/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/16 15:37:09 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	raytrace(t_map *map, int x, int y)
{
	t_sphere *sh;
	t_sphere *light;
	t_vec 		inter;
	t_vec		ray;
	int			color;
	int			i;

	i = 0;
	ray = ray_viewplane(map, x, y);
	sh = (t_sphere*)iter(map, ray, map->scene.pos);
	if (sh)
	{
		inter = ray_inter(ray, map->scene.pos,sh->t);
		color = sh->color;
		while (i < map->scene.nb_spot)
		{
			map->scene.light = &(map->scene.spot[i]);
			//printf("x: %f|y: %f|z: %f\n", map->scene.spot[i].x, map->scene.spot[i].y, map->scene.spot[i].z);
			light = (t_sphere*)iter(map, ray_light(inter, *map->scene.light),
				*map->scene.light);
			if (light)
			{
				if (sh == light)
					color = get_color(sh, inter,
							ray_light(inter, *map->scene.light), sh->color);
				else	
					color = get_shadow(map, sh, inter, color);
			//if (sh->type == 1)
			color =	get_reflection(map, sh, ray_light(inter, *map->scene.light),
					inter, color);
			}
			i++;
		}
		draw_pixel_to_image(map, x, y, color);
	}
}

void	raytracer(t_map *map)
{
	int x;
	int y;

	y = 0;
	//map->scene.sphere[0].radius = 25.0;
	//map->scene.sphere[1].radius = 25.0;
	//map->scene.light.x = 125.0;
	//map->scene.light.y = -50.0;
	//map->scene.light.z = 200.0;
	//printf("light.x: %f|light.y: %f|light.z: %f\n", map->scene)
	while (y < map->scene.h)
	{
		x = 0;
		while (x < map->scene.w)
		{
			raytrace(map, x, y);
			x++;
		}	
		//mlx_put_image_to_window(map->env.mlx, map->env.win, map->img.img, 0,0);
		y++;
	}
}
