/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:42:36 by amathias          #+#    #+#             */
/*   Updated: 2016/02/16 13:19:36 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pause_on(t_map *map)
{
	int i;
	int j;
	int color;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			color = get_hex_color(map, j, i) * 2;
			draw_pixel_to_image(map, j, i, color);
			j++;
		}
		i++;
	}
}
