/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:13:55 by amathias          #+#    #+#             */
/*   Updated: 2016/02/24 16:54:41 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int 	count_w(char **file, int line, char *word)
{
	int count;

	count = 0;
	while (file[line])
	{
		if (contain(file[line], word))
			count++;
		line++;
	}
	return (count);
}

void	malloc_objects(char **file, t_scene *scene, int line)
{
	if (!(scene->sphere = malloc(sizeof(t_sphere)
					* count_w(file, line, "sphere:"))))
		ft_parse_error(1);
	if (!(scene->plan = malloc(sizeof(t_plan)
					* count_w(file, line, "plan:"))))
		ft_parse_error(1);
	if (!(scene->cylinder = malloc(sizeof(t_cylinder)
					* count_w(file, line, "cylinder:"))))
		ft_parse_error(1);
	if (!(scene->cone = malloc(sizeof(t_cone)
					* count_w(file, line, "cone:"))))
		ft_parse_error(1);
}

void	get_object(char **file, t_scene *scene, int line)
{
	malloc_objects(file, scene, line);
	while (file[line])
	{
		if (contain(file[line], "sphere:"))
			get_sphere(file, scene->sphere, line);	
		if (contain(file[line], "plan:"))
			get_plan(file, scene->plan, line);	
		if (contain(file[line], "cylinder:"))
			get_cylinder(file, scene->cylinder, line);
		if (contain(file[line], "cone:"))
			get_cone(file, scene->cone, line);
		line++;
	}
}
