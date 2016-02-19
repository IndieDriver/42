/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 10:28:15 by amathias          #+#    #+#             */
/*   Updated: 2016/02/19 15:39:30 by amathias         ###   ########.fr       */
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

static void	print_point(t_map *map, int iter, t_point p)
{
	if (map->iso != 0)
	{
		map->grid[p.y][p.x].z = -iter;
		map->grid[p.y][p.x].color = get_color(iter);
	}
	else
		draw_pixel_to_image(map, p.x, p.y, get_color(iter));
}

void		draw_burning(void *args)
{
	t_point		p;
	t_complex	c;
	t_complex	z;
	t_complex	tmp;
	t_args		*arg;

	arg = args;
	p.y = arg->min.y;
	while (p.y < arg->max.y)
	{
		p.x = arg->min.x;
		while (p.x < arg->max.x)
		{
			c.real = 2.5 * (p.x - (WIDTH / 2)) / (WIDTH * arg->map->zoom / 2)
				+ arg->map->mx;
			c.ima = 2 * (p.y - (HEIGHT / 2)) / (HEIGHT * arg->map->zoom / 2)
				+ arg->map->my;
			z.real = 0.0;
			z.ima = 0.0;
			print_point(arg->map, get_iterat(&z, &c, &tmp, arg->map->max_iter), p);
			p.x++;
		}
		p.y++;
	}
}
