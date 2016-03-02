/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 14:16:51 by amathias          #+#    #+#             */
/*   Updated: 2016/03/02 15:40:35 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_color(t_map *map, t_vec inter, int color)
{
	t_vec light;

	light.x = inter.x - map->light.x;
	light.y = inter.y - map->light.y;
	light.z = inter.z - map->light.z;

	
}
