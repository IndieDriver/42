/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:35:35 by amathias          #+#    #+#             */
/*   Updated: 2015/12/16 17:17:36 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*strjoinfree(char *str, char *buf, int size)
{
	char *tmp;

	tmp = NULL;
	if (str)
	{
		if ((tmp = malloc(sizeof(char) *
						(ft_strlen(str) + size + 1))) == NULL)
			return (NULL);
	}
	else
	{
		if ((tmp = malloc(sizeof(char) * size + 1)) == NULL)
			return (NULL);
	}
	tmp[0] = '\0';
	if (str)
		tmp = ft_strcpy(tmp, str);
	ft_strncat(tmp, buf, size);
	free(str);
	str = NULL;	
	return (tmp);
}

char 	*shift_buf(char *buf, int start)
{
	int i;

	i = 0;
	while (buf[start])
	{
		buf[i] = buf[start];
		i++;
		start++;
	}
	buf[i] = '\0';
	return (buf);
}

int		containeof(char *buf)
{
	int i;

	i = 0;
	while(buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_buf	read_line(int const fd)
{
	static t_buf	sbuf;
	char			*tmp;

	while (1)
	{
		if (!ft_strlen(sbuf.buf))
		{
			sbuf.ret = read(fd, sbuf.buf, BUFF_SIZE);
			sbuf.buf[0] = '\0';
		}
		else
		{
			if (containeof(sbuf.buf) != -1)
			{
				tmp = strjoinfree(tmp, sbuf.buf, containeof(sbuf.buf));
				shift_buf(sbuf.buf, containeof(sbuf.buf) + 1);
				break ;
			}
			else
			{
				tmp = strjoinfree(tmp, sbuf.buf, containeof(sbuf.buf));
				sbuf.buf[0] = '\0';
			}
		}
	}
	return (tmp);
}


int		get_next_line(int const fd, char **line)
{
	*line = read_line;
	if (read_line
	return (0);
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
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			free(line);
		}
	}
}
