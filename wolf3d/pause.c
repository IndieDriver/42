/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pause.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:42:36 by amathias          #+#    #+#             */
/*   Updated: 2016/02/18 14:17:54 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	pause_on(t_map *map)
{
	int i;
	int j;
	int color;

	i = (HEIGHT / 2) - 30;
	while (i < (HEIGHT / 2) + 30)
	{
		j = (WIDTH / 2) - 50;
		while (j < (WIDTH / 2) + 50)
		{
			color = 0x003040;
			draw_pixel_to_image(map, j, i, color);
			j++;
		}
		i++;
	}
}
