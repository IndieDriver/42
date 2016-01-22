/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:17:47 by amathias          #+#    #+#             */
/*   Updated: 2016/01/22 14:30:28 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_map *map, int max_iter, double zoom)
{
	int x;
	int y;
	int i;
	t_complex c;
	t_complex z;
	t_complex old;

	c.real = -0.835;
	c.ima = -0.2321;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.real = 1.5 * (x - (WIDTH / 2)) / (WIDTH * zoom / 2);
			z.ima = 1.5 * (y - (HEIGHT / 2)) / (HEIGHT * zoom / 2);
			//printf("z.real: %f, z.ima: %f\n", z.real, z.ima);
			i = 0;
			while (i < max_iter)
			{
				old = z;
				z.real = old.real * old.real - old.ima * old.ima + c.real;
				z.ima = 2 * old.real * old.ima + c.ima;
				i++;
				if (z.real * z.real + z.ima * z.ima > 4)
					break;
			}
			draw_pixel_to_image(map, x, y, 256 * 256 * (256 - i * 10)
					+ 256 + (256 - i)
					+ (256 - i));
			//draw_pixel_to_image(map, x, y, 0xFFFFFF + (i * 1000) );
			x++;
		}
		y++;
	}
}
