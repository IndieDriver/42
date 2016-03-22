/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 15:34:45 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 16:06:53 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		reflection(int rgb, double dot)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	double			div;

	if (dot > 0.01)
		return (rgb);
	red = (rgb & 0xFF0000) >> 16;
	green = (rgb & 0xFF00) >> 8;
	blue = rgb & 0xFF;
	div = ((dot * (2.0 - 0.0)) / 0.01) + 0.0;
	red = (red + (0xFF / div)) / 2;
	blue = (blue + (0xFF / div)) / 2;
	green = (green + (0xFF / div)) / 2;
	red = red < (rgb & 0xFF0000) >> 16 ? (rgb & 0xFF0000) >> 16 : red;
	green = green < (rgb & 0xFF00) >> 8 ? (rgb & 0xFF00) >> 8 : green;
	blue = blue < (rgb & 0xFF) ? (rgb & 0xFF) : blue;
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
		return (sh->color);
	return (color);
}

int		get_reflection(t_map *map, void *shape, t_vec light,
			t_vec inter, int color)
{
	t_vec		r;
	t_sphere	*sh;
	t_vec		normal;
	double		dot;

	(void)map;
	(void)inter;
	sh = shape;
	normal = sh->normal;
	r.x = light.x + normal.x;
	r.y = light.y + normal.y;
	r.z = light.z + normal.z;
	vec_normalize(&r);
	dot = fmax(vec_dot(r, normal), 0.0);
	dot = pow(dot, 1.8);
	return (reflection(color, dot));
}
