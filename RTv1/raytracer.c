/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 20:52:26 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 16:07:20 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		average(int *n, int len)
{
	int	nb;
	int	i;

	if (len == 0)
		return (0);
	i = 0;
	nb = 0;
	while (i < len)
	{
		nb += n[i];
		i++;
	}
	nb /= len;
	return (nb);
}

int		moy_rgb(int *rgb, int len)
{
	int	red[len];
	int	green[len];
	int	blue[len];
	int i;

	i = 0;
	while (i < len)
	{
		red[i] = (rgb[i] & 0xFF0000) >> 16;
		green[i] = (rgb[i] & 0xFF00) >> 8;
		blue[i] = rgb[i] & 0xFF;
		i++;
	}
	red[0] = average(red, len);
	blue[0] = average(blue, len);
	green[0] = average(green, len);
	red[0] = red[0] > 255 ? 255 : red[0];
	blue[0] = blue[0] > 255 ? 255 : blue[0];
	green[0] = green[0] > 255 ? 255 : green[0];
	i = red[0] << 16 | green[0] << 8 | blue[0];
	return (i);
}

int		is_equal(t_vec v1, t_vec v2)
{
	if (v1.x > v2.x - 0.25 && v1.x < v2.x + 0.25)
		return (0);
	if (v1.y > v2.y - 0.25 && v1.y < v2.y + 0.25)
		return (0);
	if (v1.z > v2.z - 0.25 && v1.z < v2.z + 0.25)
		return (0);
	return (1);
}

double	get_distance(t_vec p1, t_vec p2)
{
	double dist;

	dist = sqrt(vec_dot(vec_sub(p2, p1), vec_sub(p2, p1)));
	return (dist);
}

void	raytrace(t_map *map, int x, int y)
{
	t_sphere	*sh;
	t_sphere	*light;
	t_vec		inter;
	t_vec		ray;
	int			color;
	int			i;
	int			acolor[map->scene.nb_spot];

	i = 0;
	ray = ray_viewplane(map, x, y);
	sh = (t_sphere*)iter(map, ray, map->scene.pos);
	if (sh)
	{
		inter = ray_inter(ray, map->scene.pos, sh->t);
		while (i < map->scene.nb_spot)
		{
			color = sh->color;
			map->scene.light = &(map->scene.spot[i]);
			light = (t_sphere*)iter(map, ray_light(inter, *map->scene.light),
					*map->scene.light);
			if (light)
			{
				if (sh == light)
				{
					if (get_distance(inter, *map->scene.light) - 0.5 <
						get_distance(ray_inter(
						ray_light(inter, *map->scene.light), *map->scene.light,
								light->t), *map->scene.light))
					{
						color = get_color(sh, inter,
							ray_invlight(inter, *map->scene.light), color);
						if (sh->type != 2)
							color = get_reflection(map, sh,
							ray_light(inter, *map->scene.light), inter, color);
					}
					else
						color = 0x000000;
				}
				else
					color = get_shadow(map, sh, inter, color);
			}
			acolor[i] = color;
			i++;
		}
		draw_pixel_to_image(map, x, y, moy_rgb(acolor, i));
	}
}

void	raytracer(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->scene.h)
	{
		x = 0;
		while (x < map->scene.w)
		{
			raytrace(map, x, y);
			x++;
		}
		y++;
	}
}
