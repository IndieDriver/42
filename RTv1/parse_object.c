/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:13:55 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 15:16:42 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_count(int *sphere, int *plan, int *cylinder, int *cone)
{
	*sphere = 0;
	*plan = 0;
	*cylinder = 0;
	*cone = 0;
}

int		count_w(char **file, int line, char *word)
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
	scene->nb_sph = count_w(file, line, "sphere:");
	scene->nb_plan = count_w(file, line, "plan:");
	scene->nb_cyl = count_w(file, line, "cylinder:");
	scene->nb_cone = count_w(file, line, "cone:");
	if (!(scene->sphere = (t_sphere*)malloc(sizeof(t_sphere)
					* scene->nb_sph)))
		ft_parse_error(1, line);
	if (!(scene->plan = (t_plan*)malloc(sizeof(t_plan)
					* scene->nb_plan)))
		ft_parse_error(1, line);
	if (!(scene->cylinder = (t_cylinder*)malloc(sizeof(t_cylinder)
					* scene->nb_cyl)))
		ft_parse_error(1, line);
	if (!(scene->cone = (t_cone*)malloc(sizeof(t_cone)
					* scene->nb_cone)))
		ft_parse_error(1, line);
}

void	get_object(char **file, t_scene *scene, int line)
{
	int sphere;
	int plan;
	int cylinder;
	int cone;

	init_count(&sphere, &plan, &cylinder, &cone);
	malloc_objects(file, scene, line);
	while (file[line])
	{
		if (contain(file[line], "sphere:"))
			scene->sphere[sphere++] = get_sphere(file, line);
		if (contain(file[line], "plan:"))
			scene->plan[plan++] = get_plan(file, line);
		if (contain(file[line], "cylinder:"))
			scene->cylinder[cylinder++] = get_cylinder(file, line);
		if (contain(file[line], "cone:"))
			scene->cone[cone++] = get_cone(file, line);
		line++;
	}
}
