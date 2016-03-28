/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/28 13:42:35 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		iter_spot(t_map *map, t_sphere *sh, t_sphere *light, t_vec inter)
{
	int ambient;
	int diffuse;
	int	specular;

	specular = 0x000000;
	if (light)
	{
		ambient = col_mul(sh->color, 0.2);
		diffuse = col_mul(sh->color, 0.7 *
			get_diffuse(sh, ray_invlight(inter, *map->scene.light)));
		if (sh->type != 2)
			specular = col_mul(0xFFFFFF, 1.0 *
			get_spec(sh, ray_invlight(inter, *map->scene.light),
			vec_sub(map->scene.pos, inter)));
		if (sh == light)
			return (col_add(diffuse, specular));
		else
			return (get_shadow(col_add(diffuse, specular)));
	}
	return (col_mul(sh->color, 0.2));
}

int		raytrace(t_map *map, t_vec ray)
{
	t_sphere	*sh;
	t_sphere	*light;
	t_vec		inter;
	int			i;
	int			color_array[map->scene.nb_spot * 2];

	i = 0;
	sh = (t_sphere*)iter(map, ray, map->scene.pos, 1);
	if (sh)
	{
		inter = ray_inter(ray, map->scene.pos, sh->t);
		sh->normal = get_normal(sh, inter);
		while (i < map->scene.nb_spot)
		{
			map->scene.light = &(map->scene.spot[i]);
			light = (t_sphere*)iter(map, ray_light(inter, *map->scene.light),
					*map->scene.light, 0);
			color_array[i] = iter_spot(map, sh, light, inter);
			i++;
		}
		return (col_add_array(col_mul(sh->color, 0.1), color_array, i));
	}
	return (0x000000);
}

void	raytracer(t_map *map)
{
	t_vec	ray;
	int		color;
	int		x;
	int		y;

	y = 0;
	while (y < map->scene.h)
	{
		x = 0;
		while (x < map->scene.w)
		{
			ray = ray_viewplane(map, x, y);
			color = raytrace(map, ray);
			draw_pixel_to_image(map, x, y, color);
			x++;
		}
		y++;
	}
}
