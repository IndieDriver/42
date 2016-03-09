/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:45 by amathias          #+#    #+#             */
/*   Updated: 2016/03/09 18:05:40 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int        reflection(int rgb, double dot)
{
	unsigned int    red;
	unsigned int    green;
	unsigned int    blue;

	red = (rgb & 0xFF0000) >> 16;
	green = (rgb & 0xFF00) >> 8;
	blue = rgb & 0xFF;
	dot = 1.0 - dot;
	//printf("dot: %d\n", dot);
	red *= dot;
	blue *= dot;
	green *= dot;
	red = red > 255 ? 255 : red;
	blue = blue > 255 ? 255 : blue;
	green = green > 255 ? 255 : green;
	rgb = red << 16 | green << 8 | blue;
	return (rgb);
}

int		get_reflection(t_map *map, void *shape, t_vec light, t_vec inter, int color)
{
	t_vec	r;
	t_sphere *sh;
	t_vec	normal;
	double	dot;
	double	refl;

	(void)map;
	refl = 0.5;
	sh = shape;
	normal = get_normal(shape, inter);
	if (refl > 0.0)
	{
		//if (vec_dotproduct(light, normal) > 0.0)
		//{
			r.x = light.x + normal.x;
			r.y = light.y + normal.y;
			r.z = light.z + normal.z;
			vec_normalize(&r);
			dot = fmax(vec_dotproduct(light, r), 0.0);
			dot = pow(dot, 3.0);
			return (reflection(color, dot));
		//}
		
	}
	return (/*get_color(sh, inter, light, color)*/color);
}
