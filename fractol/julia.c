/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:17:47 by amathias          #+#    #+#             */
/*   Updated: 2016/01/24 14:13:09 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_map *map, int max_iter)
{
	int x;
	int y;
	int i;
	t_complex z;
	t_complex old;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.real = 1.5 * (x - (WIDTH / 2)) / (WIDTH * map->zoom / 2);
			z.ima = 1.5 * (y - (HEIGHT / 2)) / (HEIGHT * map->zoom / 2);
			i = 0;
			while (i < max_iter)
			{
				old = z;
				z.real = old.real * old.real - old.ima * old.ima + map->c.real;
				z.ima = 2 * old.real * old.ima + map->c.ima;
				i++;
				if (z.real * z.real + z.ima * z.ima > 4)
					break;
			}
			draw_pixel_to_image(map, x, y, 256 * 256 * (256 - i * 10)
					+ 256 + (256 - i)
					+ (256 - i));
			x++;
		}
		y++;
	}
}
