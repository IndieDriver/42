/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:35:02 by amathias          #+#    #+#             */
/*   Updated: 2016/02/24 17:08:17 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_vec(char **line_split, int type, t_vec *vec)
{
	int i;

	if (!is_line_split_valid(line_split, 3))
		ft_parse_error(5);
	if (type == 1)
	{
		vec->x = ft_atoi_double(line_split[0]);
		vec->y = ft_atoi_double(line_split[1]);
		vec->z = ft_atoi_double(line_split[2]);
	}
	i = 0;
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
}

void	get_sphere(char **file, t_sphere *sph, int line)
{
	line++;
	while(file[line])
	{
		if (contain(file[line], "rgb:"))
			sph->color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);		
		if (contain(file[line], "pos:"))
			get_vec(ft_strsplit(ft_strchr(file[line], ':') + 1, ' '), 1,
					&sph->pos);
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
}

void	get_plan(char **file, t_plan *plan, int line)
{
	line++;
	(void)plan;
	while (file[line])
	{
		if (contain(file[line], "rgb:"))
			plan->color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);		
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
}

void	get_cylinder(char **file, t_cylinder *cyl, int line)
{
	line++;
	while (file[line])
	{
		if (contain(file[line], "pos:"))
			get_vec(ft_strsplit(ft_strchr(file[line], ':') + 1, ' '), 1,
					&cyl->pos);
		if (contain(file[line], "rgb:"))
			cyl->color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;
	}
}

void	get_cone(char **file, t_cone *cone, int line)
{
	line++;
	while (file[line])
	{
		if (contain(file[line], "pos:"))
			get_vec(ft_strsplit(ft_strchr(file[line], ':') + 1, ' '), 1,
					&cone->pos);
		if (contain(file[line], "rgb:"))
			cone->color = ft_atoi_hex(ft_strchr(file[line], 'x') + 1);	
		if (contain(file[line], "sphere:") || contain(file[line], "plan:")
			|| contain(file[line], "cylinder:") || contain(file[line], "cone"))
			break ;
		line++;

	}

}
