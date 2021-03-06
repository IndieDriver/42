/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 14:13:19 by amathias          #+#    #+#             */
/*   Updated: 2016/02/11 13:50:03 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		*init_mandelbrot_color(int max_iter)
{
	int *color_array;
	int i;
	int tmp;

	tmp = 0xff6600;
	if ((color_array = (int *)malloc(sizeof(int) * max_iter + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < max_iter + 1)
	{
		tmp += 0x000301;
		if (i == max_iter)
			color_array[i] = 0x000000;
		else
			color_array[i] = tmp;
		i++;
	}
	return (color_array);
}

int		*init_julia_color(int max_iter)
{
	int *color_array;
	int i;
	int tmp;

	tmp = 0xff6600;
	if ((color_array = (int *)malloc(sizeof(int) * max_iter + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < max_iter + 1)
	{
		tmp += 0x000301;
		if (tmp > 0xffffff)
			tmp = 0xffd700;
		color_array[i] = tmp;
		i++;
	}
	return (color_array);
}

int		*init_burning_color(int max_iter)
{
	int *color_array;
	int i;
	int tmp;

	tmp = 0x0f0f0f;
	if ((color_array = (int *)malloc(sizeof(int) * max_iter + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < max_iter + 1)
	{
		tmp += 0x020304;
		if (i == max_iter)
			tmp = 0xefefef;
		color_array[i] = tmp;
		i++;
	}
	return (color_array);
}
