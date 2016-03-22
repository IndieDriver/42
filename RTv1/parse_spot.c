/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:24:40 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 14:30:46 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_spot(char **file, int line)
{
	t_vec vec;

	vec = get_vec(ft_strsplit(ft_strchr(file[line], ':') + 1, ' '), 1, line);
	printf("spot.x: %f|spot.y: %f|spot.z: %f\n", vec.x, vec.y, vec.z);
	return (vec);
}

void	get_vec_list(t_scene *scene, char **file, int line)
{
	int	count;

	count = 0;
	while (file[line])
	{
		if (contain(file[line], "spot:"))
			count++;
		line++;
	}
	scene->nb_spot = count;
	scene->spot = (t_vec*)malloc(sizeof(t_vec) * count);
	count = 0;
	line = 0;
	while (file[line])
	{
		if (contain(file[line], "spot:"))
		{
			scene->spot[count] = get_spot(file, line);
			count++;
		}
		line++;
	}
}
