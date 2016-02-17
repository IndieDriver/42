/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:28:15 by amathias          #+#    #+#             */
/*   Updated: 2016/02/17 13:20:26 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_iterat(t_complex *z, t_complex *c, t_complex *tmp, int max_iter)
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

static void	print_point(t_map *map, int iter, t_point p, int *color_array)
{
	if (map->iso != 0)
	{
		map->grid[p.y][p.x].z = iter;
		map->grid[p.y][p.x].color = color_array[iter];
	}
	else
		draw_pixel_to_image(map, p.x, p.y, color_array[iter]);
}

void		draw_burning(t_map *map, int max_iter, int *color_array)
{
	t_point		p;
	t_complex	c;
	t_complex	z;
	t_complex	tmp;

	color_array = init_burning_color(max_iter);
	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			c.real = 2.5 * (p.x - (WIDTH / 2)) / (WIDTH * map->zoom / 2)
				+ map->mx;
			c.ima = 2 * (p.y - (HEIGHT / 2)) / (HEIGHT * map->zoom / 2)
				+ map->my;
			z.real = 0.0;
			z.ima = 0.0;
			print_point(map, get_iterat(&z, &c, &tmp, max_iter), p,
					color_array);
			p.x++;
		}
		p.y++;
	}
}
