/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:02:56 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 13:47:31 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		light_rgb(int rgb, double angle)
{
	int		red;
	int		green;
	int		blue;

	red = (rgb >> 16) & 0xFF;
	green = (rgb >> 8) & 0xFF;
	blue = rgb & 0xFF;
	red /= angle;
	blue /= angle;
	green /= angle;
	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 16) + blue;
	return (rgb);
}
