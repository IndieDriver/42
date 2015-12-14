/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:35:35 by amathias          #+#    #+#             */
/*   Updated: 2015/12/13 12:18:39 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*strjoinfree(char str, char buf, int size)
{
	char *tmp;

	if (str)
	{
		if ((tmp = malloc(sizeof(char) *
						(ft_strlen(str) + ft_strlen(buf) + 1))) == NULL)
			return (NULL);
	}
	else
	{
		if ((tmp = malloc(sizeof(char) * (ft_strlen(buf) + 1))) == NULL)
			return (NULL);
	}
	ft_strcpy(tmp, s1);
	ft_strncat(tmp, s1);
	free(s1);
	s1 = NULL;
	return (tmp);

}

char	*read_line(int const fd)
{
	
}

int		get_next_line(int const fd, char **line)
{
	static char buf[BUFF_SIZE + 1];
	static int ret;

	w
}

#include <fcntl.h>

int		main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			//write(1, line, ft_strlen(line));
			//write(1, "\n", 1);
			free(line);
		}
	}
}
