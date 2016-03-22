/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:35:02 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 11:23:41 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_vec(char **line_split, int type, int line)
{
	t_vec vec;
	int i;

	if (!is_line_split_valid(line_split, 3))
		ft_parse_error(5, line);
	if (type == 1)
	{
		vec.x = ft_atoi_double(line_split[0]);
		vec.y = ft_atoi_double(line_split[1]);
		vec.z = ft_atoi_double(line_split[2]);
	}
	i = 0;
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
	return (vec);
}

t_sphere	get_sphere(char **file, int line)
{
	t_sphere sph;

	line++;
	sph.type = 1;
	while(file[line])
	{
		if (contain(file[line], "rgb:"))
			sph.color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);		
		if (contain(file[line], "pos:"))
			sph.pos = get_vec(ft_strsplit(
						ft_strchr(file[line], ':') + 1, ' '), 1, line);
		if (contain(file[line], "radius"))
			sph.radius = ft_atoi(ft_strchr(file[line], ':') + 1);
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
	return (sph);
}

t_plan		get_plan(char **file, int line)
{
	t_plan plan;

	plan.type = 2;
	line++;
	while (file[line])
	{
		if (contain(file[line], "rgb:"))
			plan.color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);		
		if (contain(file[line], "pos:"))
			plan.pos = get_vec(ft_strsplit(ft_strchr(file[line], ':')
				+ 1, ' '), 1, line);
		if (contain(file[line], "normal:"))
			plan.normal = get_vec(ft_strsplit(ft_strchr(file[line], ':')
				+ 1, ' '), 1, line);
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
	return (plan);
}

t_cylinder	get_cylinder(char **file, int line)
{
	t_cylinder cyl;

	line++;
	cyl.type = 3;
	while (file[line])
	{
		if (contain(file[line], "pos:"))
			cyl.pos = get_vec(ft_strsplit(
					ft_strchr(file[line], ':') + 1, ' '), 1, line);
		if (contain(file[line], "rgb:"))
			cyl.color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);
		if (contain(file[line], "radius:"))
			cyl.radius = ft_atoi(ft_strchr(file[line], ':') + 1);
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
	return (cyl);
}

t_cone get_cone(char **file, int line)
{
	t_cone cone;

	line++;
	cone.type = 4;
	while (file[line])
	{
		if (contain(file[line], "pos:"))
			cone.pos = get_vec(
				ft_strsplit(ft_strchr(file[line], ':') + 1, ' '), 1, line);
		if (contain(file[line], "rgb:"))
			cone.color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
	return (cone);
}
