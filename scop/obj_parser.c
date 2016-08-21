/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 15:55:42 by amathias          #+#    #+#             */
/*   Updated: 2016/08/21 14:44:32 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	add_tri(char *line, t_obj *obj)
{
	t_vec4 vec;

	vec = get_vec_4(ft_strsplit(line, ' '));
	if (obj->tri)
		ft_lstpushback(obj->tri,
			ft_lstnew((void*)&vec, sizeof(t_vec4)));
	else
		obj->tri = ft_lstnew(&vec, sizeof(t_vec4));
}

void	add_vertex(char *line, t_obj *obj)
{
	t_vec3	vec;
	t_list	*elem;

	vec = get_vec(ft_strsplit(line, ' '));
	if (obj->vertex)
	{	
		elem = ft_lstnew(&vec, sizeof(t_vec3));
		if (elem)
			ft_lstpushback(obj->vertex, elem);
		else
			ft_putstr("error creating element\n");
	}
	else
		obj->vertex = ft_lstnew((void*)&vec, sizeof(t_vec3));
}

void	process_line(char *line, t_obj *obj)
{
	if (!ft_strchr(line, '#'))
	{
		if (ft_strstr(line, "mtllib "))
			obj->mtllib = ft_strdup(ft_strchr(line, ' ') + 1);
		if (ft_strstr(line, "o "))
			obj->name = ft_strdup(ft_strchr(line, ' ') + 1);
		if (ft_strstr(line, "v "))
			add_vertex(ft_strchr(line, ' ') + 1, obj);
		if (ft_strstr(line, "f "))
			add_tri(ft_strchr(line, ' ') + 1, obj);
	}
}

float	*parse_obj_file(char *file_name, t_map *map)
{
	char *line;
	t_obj obj;
	int fd;

	obj.name = NULL;
	obj.mtllib = NULL;
	obj.vertex = NULL;
	obj.tri = NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr("can't read file\n");
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		process_line(line, &obj);
		free(line);
	}
	close(fd);
	return (obj_reconstruct(&obj, map));
}
