/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:02:56 by amathias          #+#    #+#             */
/*   Updated: 2016/03/23 18:23:48 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		col_mul(int c1, double mul)
{
	int red;
	int green;
	int blue;

	red = ((c1 & 0xFF0000) >> 16) * mul;
	green = ((c1 & 0xFF00) >> 8) * mul;
	blue = (c1 & 0xFF) * mul;
	red = red > 0xFF ? 0xFF : red;
	green = green > 0xFF ? 0xFF : green;
	blue = blue > 0xFF ? 0xFF : blue;
	return (red << 16 | green << 8 | blue);
}

int		col_add_mul(int c1, int c2, double mul)
{
	int	red;
	int green;
	int blue;

	//c1 = col_mul(c1, mul);
	c2 = col_mul(c2, mul);
	red = ((c1 & 0xFF0000) >> 16) + ((c2 & 0xFF0000) >> 16);
	green = ((c1 & 0xFF00) >> 8) + ((c2 & 0xFF00) >> 8);
	blue = (c1 & 0xFF) + (c2 & 0xFF);
	red = red > 0xFF ? 0xFF : red;
	green = green > 0xFF ? 0xFF : green;
	blue = blue > 0xFF ? 0xFF : blue;
	return (red << 16 | green << 8 | blue);
}

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

int		average_rgb(int *rgb, int len)
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
