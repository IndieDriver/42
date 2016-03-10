/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:45 by amathias          #+#    #+#             */
/*   Updated: 2016/03/10 16:01:57 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int        reflection(int rgb, double dot)
{
	unsigned int    red;
	unsigned int    green;
	unsigned int    blue;
	
	if (dot > 0.1)
		return (rgb);
	red = (rgb & 0xFF0000) >> 16;
	green = (rgb & 0xFF00) >> 8;
	blue = rgb & 0xFF;
	dot = 1.0 - dot;
	//red = (red + (0xFF) * dot) / 2;
	//blue = (blue + (0xFF) * dot) / 2;
	//green = (green + (0xFF) * dot) / 2;
	red *= dot;
	blue *= dot;
	green *= dot;
	red = red > 255 ? 255 : red;
	blue = blue > 255 ? 255 : blue;
	green = green > 255 ? 255 : green;
	rgb = red << 16 | green << 8 | blue;
	return (rgb);
}

int		get_reflected_shape(t_map *map, t_vec ray, t_vec inter, int color)
{
	t_sphere *sh;

	sh = (t_sphere*)iter(map, ray, inter);
	if (sh)
	{
		return (sh->color);
	}
	return (color);
}	

int		get_reflection(t_map *map, void *shape, t_vec light, t_vec inter, int color)
{
	t_vec	r;
	t_sphere *sh;
	t_vec	normal;
	double	dot;

	(void)map;
	sh = shape;
	normal = get_normal(shape, inter);
	if (vec_dotproduct(light, normal) < 0.0) //TODO: DEBUG THAT SHIT
	{
		r.x = light.x + normal.x;
		r.y = light.y + normal.y;
		r.z = light.z + normal.z;
		vec_normalize(&r);
		dot = fmax(vec_dotproduct(normal, r), 0.0);
		dot = pow(dot, 2.0);
		return (reflection(color, dot));
		
	}
	return (color);
}
