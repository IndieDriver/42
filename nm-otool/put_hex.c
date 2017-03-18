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

void			ft_put_addr(size_t n)
{
	char		buf[17];
	int			ntmp;
	int			len;
	int			i;

	len = 16;
	i = len - 1;
	buf[16] = '\0';
	ft_memset(buf, '0', 16);
	while (n != 0)
	{
		ntmp = (n % 16);
		buf[i] = (ntmp > 9) ? (ntmp - 10) + 'a' : ntmp + '0';
		n = n / 16;
		i--;
	}
	write(1, buf, 16);
}
