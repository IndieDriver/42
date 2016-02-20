/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   siegel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:53:39 by amathias          #+#    #+#             */
/*   Updated: 2016/02/20 12:54:31 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	get_iter(t_complex *z, t_complex *old, int max_iter)
{
	int i;

	i = 0;
	while (i < max_iter)
	{
		*old = *z;
		z->real = old->real * old->real - old->ima * old->ima - 0.390541;
		z->ima = 2 * old->real * old->ima + 0.586788;
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

void		draw_siegel(void *args)
{
	t_point		p;
	t_complex	z;
	t_complex	old;
	t_args		*arg;

	arg = args;
	p.y = arg->min.y;
	while (p.y < arg->max.y)
	{
		p.x = arg->min.x;
		while (p.x < arg->max.x)
		{
			z.real = 1.5 * (p.x - (WIDTH / 2)) / (WIDTH * arg->map->zoom / 2)
				+ arg->map->mx;
			z.ima = 1.5 * (p.y - (HEIGHT / 2)) / (HEIGHT * arg->map->zoom / 2)
				+ arg->map->my;
			print_point(arg->map, get_iter(&z, &old, arg->map->max_iter), p);
			p.x++;
		}
		p.y++;
	}
}
