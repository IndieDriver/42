/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/24 17:34:25 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	get_distance(t_vec p1, t_vec p2)
{
	double dist;

	dist = sqrt(vec_dot(vec_sub(p2, p1), vec_sub(p2, p1)));
	return (dist);
}

int		iter_spot(t_map *map, t_sphere *sh, t_sphere *light, t_vec inter)
{
	int ambient;
	int diffuse;
	int	specular;
	int i;
	int j;
	int color_array[map->scene.nb_spot * 2];

	i = 0;
	j = 0;
	while (i < map->scene.nb_spot)
	{
		map->scene.light = &map->scene.spot[i];
		light = (t_sphere*)iter(map, ray_light(inter, *map->scene.light),
					*map->scene.light, 0);
		if (light)
		{
			ambient = col_mul(sh->color, 0.2);
			diffuse = col_mul(sh->color, 0.7 *
				get_diffuse(sh, ray_invlight(inter, *map->scene.light)));
			specular = col_mul(0xFFFFFF, 1.0 *
				get_spec(sh, ray_invlight(inter, *map->scene.light),
				vec_sub(map->scene.pos, inter)));
			if (sh == light)
			{
				color_array[j] = diffuse;
				color_array[++j] = specular;
			}
			else
				color_array[j] = get_shadow(map, sh, inter,
						col_add3(ambient, diffuse, specular));	
		}
		j++;
		i++;
	}
	return (col_add_array(ambient, color_array, j));
}

int		raytrace(t_map *map, t_vec ray)
{
	t_sphere	*sh;
	t_sphere	*light;
	t_vec		inter;
	int			i;
	//int			acolor[map->scene.nb_spot];

	i = 0;
	sh = (t_sphere*)iter(map, ray, map->scene.pos, 1);
	light = NULL;
	if (sh)
	{
		inter = ray_inter(ray, map->scene.pos, sh->t);
		sh->normal = get_normal(sh, inter);
		//while (i < map->scene.nb_spot)
		//{
		//	map->scene.light = &(map->scene.spot[i]);
		//	light = (t_sphere*)iter(map, ray_light(inter, *map->scene.light),
		//			*map->scene.light, 0);
		//	acolor[i] = iter_spot(map, sh, light, inter);
		//	i++;
		//}
		return (iter_spot(map, sh, light, inter));
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
