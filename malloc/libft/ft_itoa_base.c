/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:11:09 by amathias          #+#    #+#             */
/*   Updated: 2015/12/11 15:25:11 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n, int base)
{
	int i;

	i = 1;
	if (n < 0)
		i++;
	while (n > base - 1 || n < -(base - 1))
	{
		i++;
		n = n / base;
	}
	return (i);
}

char		*ft_itoa_base(int n, int base)
{
	char	*tmp;
	int		ntmp;
	int		neg;
	int		i;

	i = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	if ((tmp = malloc(sizeof(char) * ft_intlen(n, base) + 1)) == NULL)
		return (NULL);
	if (n == 0)
		tmp[i++] = '0';
	while (n != 0)
	{
		ntmp = ABS((n % base));
		tmp[i++] = (ntmp > 9) ? (ntmp - 10) + 'a' : ntmp + '0';
		n = n / base;
	}
	if (neg)
		tmp[i++] = '-';
	tmp[i] = '\0';
	return (ft_strrev(tmp));
}
