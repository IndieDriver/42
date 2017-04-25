/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 16:35:52 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 15:39:55 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			is_split_valid(char **line_split, int size)
{
	int i;

	i = 0;
	while (line_split[i])
		i++;
	if (i == size)
		return (1);
	return (0);
}

t_vec4		get_vec_4(char **line_split)
{
	t_vec4	vec;
	int		i;

	if (is_split_valid(line_split, 4) || is_split_valid(line_split, 3))
	{
		vec.x = ft_atoi_double(line_split[0]);
		vec.y = ft_atoi_double(line_split[1]);
		vec.z = ft_atoi_double(line_split[2]);
	}
	else
	{
		ft_putstr("Error: tri not well formated\n");
		exit(0);
	}
	vec.w = is_split_valid(line_split, 4) ?
		ft_atoi_double(line_split[3]) : -1.0f;
	i = 0;
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
	return (vec);
}

t_vec3		get_vec(char **line_split)
{
	t_vec3	vec;
	int		i;

	if (!is_split_valid(line_split, 3))
	{
		ft_putstr("Error: vertex not well formated");
		exit(0);
	}
	vec.x = ft_atoi_double(line_split[0]);
	vec.y = ft_atoi_double(line_split[1]);
	vec.z = ft_atoi_double(line_split[2]);
	i = 0;
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
	return (vec);
}

void		init_index(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

double		ft_atoi_double(char *str)
{
	int			i;
	double		ent;
	double		dec;
	double		sign;
	int			j;

	init_index(&i, &j);
	sign = 1.0f;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
		i++;
	if (str[i] == '-')
		sign = -1.0f;
	ent = ft_atoi(str + i);
	ent = ent > 0.0 ? ent : -ent;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] != '.')
		return (ent);
	i++;
	while (str[i + j] == '0')
		j++;
	dec = ft_atoi(str + i);
	while (dec >= 1)
		dec /= 10;
	while (j != 0)
	{
		dec /= 10;
		j--;
	}
	return (sign * (dec + ent));
}
