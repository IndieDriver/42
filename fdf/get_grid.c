/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:21:06 by amathias          #+#    #+#             */
/*   Updated: 2016/01/10 15:43:48 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_strsplitmap(char *str, t_map *map)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * map->height + 1);
	while (i < map->height)
	{
		tab[i] = (char*)malloc(sizeof(char) * map->width + 1);
		j = 0;
		while (j < map->width)
		{
			tab[i][j] = str[j + i * map->width];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = "\0";
	return (tab);
}

int		get_width(t_map *map, char **line)
{
	int	i;
	int	j;
	int	width;

	width = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (line[i][j])
		{
			if (line[i][j] == ' ')
				map->width++;
			while (line[i][j] == ' ')
				j++;
			if (line[i][j - 1] != ' ')
				j++;
		}
		if (i > 0 && width != map->width)
			ft_error();
		else
			width = map->width;
		map->width = 0;
		i++;
	}
	return (width);
}

int		get_inc_j(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	return (i);
}

t_point		**ft_create_tab_t_point(char **line, t_map *map, int offset)
{
	t_point	**tab;
	int		i;
	int		j;
	int		n;

	n = 0;
	map->width = get_width(map, line);
	tab = (t_point**)malloc(sizeof(t_point*) * (map->height + 1));
	i = 0;
	while (i < map->height)
	{
		tab[i] = (t_point*)malloc(sizeof(t_point) * (map->width));
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			tab[i][n].z = ft_atoi(&line[i][j]);
			tab[i][n].x = n*offset - tab[i][n].z;
			tab[i][n].y = i*offset - tab[i][n].z;
			if (ft_strchr(&line[i][j], ','))
			{
				tab[i][n].color = ft_strsub(ft_strchr(&line[i][j],
				','), 0, ft_strlen(&line[i][j]));
			}
			else
				tab[i][j].color = NULL;
			while (line[i][j] == ' ')
				j++;
			if (tab[i][n].color)
			{
				j += get_inc_j(&line[i][j]);
			}
		}
		i++;
	}
	return (tab);
}

char	*ft_strjoinendl(char *s1, char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (s1)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2))))
				return (NULL);
		ft_bzero(tmp, ft_strlen(s1) + ft_strlen(s2) + 2);
	}
	else
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (ft_strlen(s2) + 2))))
			return (NULL);
		ft_bzero(tmp, ft_strlen(s2) + 2);
	}
	if (s1)
	{
		tmp = ft_strcpy(s1, tmp);
		free(s1);
		s1 = NULL;
	}
	ft_strcat(tmp,s2);
	tmp[ft_strlen(tmp)] = '\n';
	return (tmp);
}

t_map	*ft_parse(int const fd, t_map *map)
{
	char	*tmpmap;
	int		x;
	char	**line;

	line = NULL;
	tmpmap = NULL;
	while ((x = get_next_line(fd, line)) == 1)
	{
		map->height++;
		tmpmap = ft_strjoinendl(tmpmap, *line);
	}
	line = ft_strsplitmap(tmpmap, map);
	map->map = ft_create_tab_t_point(line, map,20);
	return (map);
}
