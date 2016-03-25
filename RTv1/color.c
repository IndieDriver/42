/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:02:56 by amathias          #+#    #+#             */
/*   Updated: 2016/03/25 13:45:32 by amathias         ###   ########.fr       */
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

int		col_add_array(int ambient, int *c, int nb)
{
	int red;
	int green;
	int blue;
	int i;

	i = 0;
	red = (ambient & 0xFF0000) >> 16;
	green = (ambient & 0xFF00) >> 8;
	blue = (ambient & 0xFF);
	while (i < nb)
	{
		red += ((c[i] & 0xFF0000) >> 16);
		green += ((c[i] & 0xFF00) >> 8);
		blue += (c[i] & 0xFF);
		i++;
	}
	red = red > 0xFF ? 0xFF : red;
	green = green > 0xFF ? 0xFF : green;
	blue = blue > 0xFF ? 0xFF : blue;
	return (red << 16 | green << 8 | blue);
}

int		col_add3(int c1, int c2, int c3)
{
	int	red;
	int green;
	int blue;

	red = (((c1 & 0xFF0000) >> 16) +
			((c2 & 0xFF0000) >> 16) + ((c3 & 0xFF0000) >> 16));
	green = (((c1 & 0xFF00) >> 8) + ((c2 & 0xFF00) >> 8)
			+ ((c3 & 0xFF00) >> 8));
	blue = ((c1 & 0xFF) + (c2 & 0xFF) + (c3 & 0xFF));
	red = red > 0xFF ? 0xFF : red;
	green = green > 0xFF ? 0xFF : green;
	blue = blue > 0xFF ? 0xFF : blue;
	return (red << 16 | green << 8 | blue);
}

int		col_add(int c1, int c2)
{
	int	red;
	int green;
	int blue;

	red = (((c1 & 0xFF0000) >> 16) + ((c2 & 0xFF0000) >> 16));
	green = (((c1 & 0xFF00) >> 8) + ((c2 & 0xFF00) >> 8));
	blue = ((c1 & 0xFF) + (c2 & 0xFF));
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

	c2 = col_mul(c2, mul);
	red = ((c1 & 0xFF0000) >> 16) + ((c2 & 0xFF0000) >> 16);
	green = ((c1 & 0xFF00) >> 8) + ((c2 & 0xFF00) >> 8);
	blue = (c1 & 0xFF) + (c2 & 0xFF);
	red = red > 0xFF ? 0xFF : red;
	green = green > 0xFF ? 0xFF : green;
	blue = blue > 0xFF ? 0xFF : blue;
	return (red << 16 | green << 8 | blue);
}
