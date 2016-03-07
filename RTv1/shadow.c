/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:23:44 by amathias          #+#    #+#             */
/*   Updated: 2016/03/07 15:21:32 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	init_lightpos(t_vec lightpos)
{
	t_vec light;

	light.x = lightpos.x - 10.0;
	light.y = lightpos.y;
	light.z = lightpos.z - 10.0;
	return (light);
}

t_vec	get_lightpos(t_vec lightpos, double off_x, double off_y)
{
	t_vec light;

	light = init_lightpos(lightpos);
	light.x += off_x;
	light.z += off_y;
	return (light);
}

int		get_shadow_color(int color, int nb)
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	double		div;

	printf("nb: %d\n",nb);
	div = (((nb) * (1.0 - 0.1)) / 81.0) + 0.1;
	printf("div: %f\n", div);
	red = (color & 0xFF0000) >> 16;
	green = (color & 0xFF00) >> 8;
	blue = color & 0xFF;
	red *= div;
	blue *= div;
	green *= div;
	red = red > 255 ? 255 : red;
	blue = blue > 255 ? 255 : blue;
	green = green > 255 ? 255 : green;
	return (red << 16 | green << 8 | blue);
}

int		get_shadow(t_map *map, void *shape, t_vec inter, t_vec lightpos)
{
	t_sphere *light;
	int i;
	int j;
	double	off_x;
	double	off_y;
	int count;
	t_sphere *sph;

	sph = shape;
	i = 0;
	off_x = 2.0;
	off_y = 2.0;
	count = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			light = (t_sphere*)iter(map,
				ray_light(inter, get_lightpos(lightpos, j * off_x, i * off_y))
				, get_lightpos(lightpos, j * off_x, i * off_y));
			if (shape == light)
				count++;
			j++;
		}
		i++;
	}
	//color = get_shadow_color(color, count);	
	//color = 0x000000;
	//printf("%#08x\n", color);
	return (get_shadow_color(sph->color, count));
}
