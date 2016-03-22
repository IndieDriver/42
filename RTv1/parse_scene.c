/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:39:08 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 15:11:16 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		is_line_split_valid(char **line_split, int nb)
{
	int i;

	i = 0;
	while (line_split[i])
		i++;
	return (i == nb);
}

void	process_scene(char **line_split, int type, t_scene *scene, int line)
{
	int i;

	if (!is_line_split_valid(line_split, type == 1 ? 3 : 2))
		type == 1 ? ft_parse_error(3, line) : ft_parse_error(4, line);
	if (type == 1)
	{
		scene->pos.x = ft_atoi_double(line_split[0]);
		scene->pos.y = ft_atoi_double(line_split[1]);
		scene->pos.z = ft_atoi_double(line_split[2]);
	}
	else
	{
		scene->w = ft_atoi(line_split[0]);
		scene->h = ft_atoi(line_split[1]);
	}
	i = 0;
	while (line_split[i])
	{
		free(line_split[i]);
		i++;
	}
	free(line_split);
}

void	get_scene(char **file, t_scene *sc, int line)
{
	sc->w = 0;
	sc->h = 0;
	while (file[line])
	{
		if (contain(file[line], "camera:"))
			process_scene(ft_strsplit(
					ft_strchr(file[line], ':') + 1, ' '), 1, sc, line);
		if (contain(file[line], "screen:"))
		{
			process_scene(ft_strsplit(
					ft_strchr(file[line], ':') + 1, ' '), 0, sc, line);
			process_scene(ft_strsplit(
					ft_strchr(file[line], ':') + 1, ' '), 0, sc, line);
		}
		if (sc->w != 0 && sc->h != 0)
			break ;
		line++;
	}
	get_vec_list(sc, file, 0);
}
