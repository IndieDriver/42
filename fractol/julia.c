/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 11:17:47 by amathias          #+#    #+#             */
/*   Updated: 2016/02/12 09:58:10 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_iter(t_map *map, t_complex *z, t_complex *old, int max_iter)
{
	int i;

	i = 0;
	while (i < max_iter)
	{
		*old = *z;
		z->real = old->real * old->real - old->ima * old->ima + map->c.real;
		z->ima = 2 * old->real * old->ima + map->c.ima;
		i++;
		if (z->real * z->real + z->ima * z->ima > 4)
			break ;
	}
	return (i);
}

void	draw_julia(t_map *map, int max_iter, int t)
{
	t_point		p;
	int			*color_array;
	t_complex	z;
	t_complex	old;

	color_array = init_julia_color(max_iter);
	p.y = 0;
	while (p.y < HEIGHT)
	{
		p.x = 0;
		while (p.x < WIDTH)
		{
			z.real = 1.5 * (p.x - (WIDTH / 2)) / (WIDTH * map->zoom / 2) + map->mx;
			z.ima = 1.5 * (p.y - (HEIGHT / 2)) / (HEIGHT * map->zoom / 2) + map->my;
			p.color = get_iter(map, &z, &old, max_iter);
			if (t != 0)
			{
				map->grid[p.y][p.x].z = p.color;
				map->grid[p.y][p.x].color = color_array[p.color];
			}
			else
				draw_pixel_to_image(map, p.x, p.y, color_array[p.color]);
			p.x++;
		}
		p.y++;
	}
}
