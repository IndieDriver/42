/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:28:15 by amathias          #+#    #+#             */
/*   Updated: 2016/02/11 15:01:22 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_iterat(t_complex *z, t_complex *c, t_complex *tmp, int max_iter)
{
	int i;

	i = 0;
	while (i < max_iter)
	{
		z->real = fabs(z->real);
		z->ima = fabs(z->ima);
		tmp->real = z->real * z->real - z->ima * z->ima + c->real;
		z->ima = 2 * z->real * z->ima + c->ima;
		z->real = tmp->real;
		i++;
		if (z->real * z->real + z->ima * z->ima > 4)
			break ;
	}
	return (i);
}

void	draw_burning(t_map *map, int max_iter, int *color_array)
{
	int			x;
	int			y;
	t_complex	c;
	t_complex	z;
	t_complex	tmp;

	color_array = init_burning_color(max_iter);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.real = 2.5 * (x - (WIDTH / 2)) / (WIDTH * map->zoom / 2) + map->mx;
			c.ima = 2 * (y - (HEIGHT / 2)) / (HEIGHT * map->zoom / 2) + map->my;
			z.real = 0.0;
			z.ima = 0.0;
			draw_pixel_to_image(map, x, y,
					color_array[get_iterat(&z, &c, &tmp, max_iter)]);
			x++;
		}
		y++;
	}
}
