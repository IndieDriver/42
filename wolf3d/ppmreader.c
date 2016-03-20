/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppmreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 11:28:56 by amathias          #+#    #+#             */
/*   Updated: 2016/03/20 13:13:30 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	get_color(int fd)
{
	char	*line;
	int		red;
	int		green;
	int		blue;

	get_next_line(fd, &line);
	red = ft_atoi(line);
	free(line);
	get_next_line(fd, &line);
	green = ft_atoi(line);
	free(line);
	get_next_line(fd, &line);
	blue = ft_atoi(line);
	free(line);
	return (256 * 256 * blue + 256 * green + red);
}

int	*get_line(int fd, int size)
{
	int i;
	int *line;

	if (!(line = (int*)malloc(sizeof(int) * (size))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		line[i] = get_color(fd);
		i++;
	}
	return (line);
}

int	**get_texture(char *file_name, int size)
{
	int		i;
	int		fd;
	int		**tex;
	char	*tmp;

	i = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	if (!(tex = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	get_next_line(fd, &tmp);
	free(tmp);
	get_next_line(fd, &tmp);
	free(tmp);
	while (i < size)
	{
		tex[i] = get_line(fd, size);
		i++;
	}
	return (tex);
}
