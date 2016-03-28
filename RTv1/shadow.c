/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:23:44 by amathias          #+#    #+#             */
/*   Updated: 2016/03/28 13:42:23 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_shadow_color(int color, int nb)
{
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	double			div;

	div = (((nb) * (1.0 - 0.3)) / 256.0) + 0.3;
	red = (color & 0xFF0000) >> 16;
	green = (color & 0xFF00) >> 8;
	blue = color & 0xFF;
	red *= div;
	blue *= div;
	green *= div;
	red = red > 255 ? 255 : red;
	blue = blue > 255 ? 255 : blue;
	green = green > 255 ? 255 : green;
	return (red << 16 | green << 8 | blue);
}

int		get_shadow(int color)
{
	return (get_shadow_color(color, 0));
}
