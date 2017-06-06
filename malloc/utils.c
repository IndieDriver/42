/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:58:34 by amathias          #+#    #+#             */
/*   Updated: 2017/03/11 13:06:27 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int				is_chunk_free(t_chunk *chunk)
{
	int i;

	i = 0;
	while (i < BLOCKS_MAX)
	{
		if (chunk->blocks[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static int		size_hex(size_t n)
{
	int i;

	i = 1;
	while (n > 16)
	{
		i++;
		n = n / 16;
	}
	return (i);
}

void			ft_put_addr(size_t n)
{
	char		buf[64];
	int			ntmp;
	int			len;
	int			i;

	len = size_hex(n);
	i = len;
	buf[i] = '\0';
	while (n != 0)
	{
		ntmp = (n % 16);
		buf[i] = (ntmp > 9) ? (ntmp - 10) + 'a' : ntmp + '0';
		n = n / 16;
		i--;
	}
	write(1, buf, len);
}
