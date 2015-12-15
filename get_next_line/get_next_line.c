/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:35:35 by amathias          #+#    #+#             */
/*   Updated: 2015/12/15 18:37:44 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*strjoinfree(char *str, char *buf, int size)
{
	char *tmp;
	//printf("STRJOIN BEFORE:\n%s|%s|%d\n",str,buf,size);
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
	//printf("STRJOIN AFTER:\n%s|%d\n",tmp,size);
	return (tmp);
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

char 	*shuffle_buf(char *buf, int start)
{
	int i;

	i = 0;
	//printf("BUFFER:\n%s\n",buf);
	while (buf[start])
	{
		buf[i] = buf[start];
		i++;
		start++;
	}
	buf[i] = '\0';
	//printf("SHUFFLED BUF:\n%s\n",buf);
	return (buf);
}
int		get_next_line(int const fd, char **line)
{
	char *tmp;
	static t_buf sbuf;

	tmp = NULL;
	while (1)
	{
		//printf("while(1)\n");
		if(!ft_strlen(sbuf.buf))
		{
			//printf("ft_strlen(sbuf.buf)\n");
			sbuf.ret = read(fd, sbuf.buf, BUFF_SIZE);
			sbuf.buf[sbuf.ret] = '\0';
			printf("%s\n",sbuf.buf);
		}
		else
		{
			if (containeof(sbuf.buf) != -1)
			{
				//printf("containeof(sbuf.buf)\n");
				tmp = strjoinfree(tmp, sbuf.buf, containeof(sbuf.buf));
				shuffle_buf(sbuf.buf, containeof(sbuf.buf) + 1);
				break ;
			}
			else
			{
				ft_strlen(sbuf.buf) < BUFF_SIZE ? sbuf.end = 0 : sbuf.end = 1;
				tmp = strjoinfree(tmp, sbuf.buf, BUFF_SIZE);
				sbuf.buf[0] = '\0';
			}
		}
	}
	*line = tmp;
	return (sbuf.end);
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
