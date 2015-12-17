/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:35:35 by amathias          #+#    #+#             */
/*   Updated: 2015/12/17 14:49:35 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		containeof(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*shift_buf(char *buf, int start)
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

int		get_next_line(int const fd, char **line)
{
	static t_buf	sbuf;
	char			*tmp;

	tmp = NULL;
	while (1)
	{
		if (!ft_strlen(sbuf.buf))
		{
			if ((sbuf.ret = read(fd, sbuf.buf, BUFF_SIZE)) == -1)
				return (-1);
			sbuf.buf[sbuf.ret] = '\0';
			if (!sbuf.ret)
				break ;
		}
		else
		{
			if (containeof(sbuf.buf) != -1)
			{
				if (!(tmp = strjoinfree(tmp, sbuf.buf, containeof(sbuf.buf))))
					return (-1);
				shift_buf(sbuf.buf, containeof(sbuf.buf) + 1);
				break ;
			}
			else
			{
				if (!(tmp = strjoinfree(tmp, sbuf.buf, BUFF_SIZE)))
					return (-1);
				sbuf.buf[0] = '\0';
			}
		}
	}
	return ((*line = tmp) && sbuf.ret != 0);
}
