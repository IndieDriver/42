/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:35:02 by amathias          #+#    #+#             */
/*   Updated: 2016/02/27 14:34:11 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec	get_vec(char **line_split, int type)
{
	t_vec vec;
	int i;

	if (!is_line_split_valid(line_split, 3))
		ft_parse_error(5);
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

	//if (!(sph = (t_sphere*)malloc(sizeof(t_sphere))))
	//	ft_parse_error(1);
	line++;
	while(file[line])
	{
		if (contain(file[line], "rgb:"))
			sph.color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);		
		if (contain(file[line], "pos:"))
			sph.pos = get_vec(ft_strsplit(ft_strchr(file[line], ':') + 1, ' '), 1);
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
	printf("pos.x: %f| y: %f|z: %f\n", sph.pos.x, sph.pos.y, sph.pos.z);
	return (sph);
}

t_plan		*get_plan(char **file, int line)
{
	t_plan *plan;

	if (!(plan = (t_plan*)malloc(sizeof(t_plan))))
		ft_parse_error(1);
	line++;
	while (file[line])
	{
		if (contain(file[line], "rgb:"))
			plan->color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);		
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
	return (plan);
}

t_cylinder	*get_cylinder(char **file, int line)
{
	t_cylinder *cyl;

	if (!(cyl = (t_cylinder*)malloc(sizeof(t_cylinder))))
		ft_parse_error(1);
	line++;
	while (file[line])
	{
		if (contain(file[line], "pos:"))
			cyl->pos = get_vec(ft_strsplit(ft_strchr(file[line], ':') + 1, ' '), 1);
		if (contain(file[line], "rgb:"))
			cyl->color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
	return (cyl);
}

t_cone *get_cone(char **file, int line)
{
	t_cone *cone;

	if (!(cone = (t_cone*)malloc(sizeof(t_cone))))
		ft_parse_error(1);
	line++;
	while (file[line])
	{
		if (contain(file[line], "pos:"))
			cone->pos = get_vec(ft_strsplit(ft_strchr(file[line], ':') + 1, ' '), 1);
		if (contain(file[line], "rgb:"))
			cone->color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);	
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
	return (cone);
}
