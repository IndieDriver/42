/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 11:58:34 by amathias          #+#    #+#             */
/*   Updated: 2017/03/18 15:18:22 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

void	ft_put_addr_64(size_t n)
{
	char		buf[64];
	int			ntmp;
	int			len;
	int			i;

	len = 16;
	i = len - 1;
	buf[len] = '\0';
	ft_memset(buf, '0', len);
	while (n != 0)
	{
		ntmp = (n % len);
		buf[i] = (ntmp > 9) ? (ntmp - 10) + 'a' : ntmp + '0';
		n = n / len;
		i--;
	}
	write(1, buf, len);
}

void	ft_put_addr_32(size_t n)
{
	char		buf[64];
	int			ntmp;
	int			len;
	int			i;

	len = 16;
	i = len - 1;
	buf[len] = '\0';
	ft_memset(buf, '0', len);
	while (n != 0)
	{
		ntmp = (n % len);
		buf[i] = (ntmp > 9) ? (ntmp - 10) + 'a' : ntmp + '0';
		n = n / len;
		i--;
	}
	write(1, buf + 8, len / 2);
}

void	ft_put_hex(unsigned char n)
{
	char		buf[3];
	int			ntmp;
	int			len;
	int			i;

	len = 2;
	i = len - 1;
	buf[len] = '\0';
	ft_memset(buf, '0', len);
	while (n != 0)
	{
		ntmp = (n % 16);
		buf[i] = (ntmp > 9) ? (ntmp - 10) + 'a' : ntmp + '0';
		n = n / 16;
		i--;
	}
	write(1, buf, 2);
}
