/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 15:55:42 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 17:00:59 by amathias         ###   ########.fr       */
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
		if (ft_strstr(line, "v "))
			add_vertex(ft_strchr(line, ' ') + 1, obj);
		if (ft_strstr(line, "f "))
			add_tri(ft_strchr(line, ' ') + 1, obj);
	}
}

void	free_obj(t_obj *obj)
{
	ft_lstdel(&obj->vertex, obj_delete_link);
	ft_lstdel(&obj->tri, obj_delete_link);
	if (obj->vertex != NULL)
		free(obj->vertex);
	if (obj->tri != NULL)
		free(obj->tri);
}

void	parse_obj_file(char *file_name, t_map *map)
{
	char	*line;
	t_obj	obj;
	int		fd;

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
	obj_reconstruct_indice(&obj, map);
	obj_reconstruct(map);
	free_obj(&obj);
}
