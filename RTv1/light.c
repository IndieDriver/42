/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 14:16:51 by amathias          #+#    #+#             */
/*   Updated: 2016/03/16 11:33:37 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int        light_rgb(int rgb, double angle)
{
	int    red;
	int    green;
	int    blue;

	red = (rgb & 0xFF0000) >> 16;
	green = (rgb & 0xFF00) >> 8;
	blue = rgb & 0xFF;
	red *= angle;
	blue *= angle;
	green *= angle;
	red = red > 255 ? 255 : red;
	blue = blue > 255 ? 255 : blue;
	green = green > 255 ? 255 : green;
	rgb = red << 16 | green << 8 | blue;
	return (rgb);
}

int		get_color(void *shape, t_vec inter, t_vec light, int color)
{
	t_vec	nor;
	double	angle;
	int		c;
	t_sphere *sph;

	sph = shape;
	nor = get_normal(shape, inter);
	angle = acos(vec_dotproduct(nor, light));
	if (angle <= 0)
		c = 0x000000;
	else
		c = light_rgb(color, angle * 0.5);
	//if (sph->type == 2)
	//	return (sph->color);
	return (c);
}
