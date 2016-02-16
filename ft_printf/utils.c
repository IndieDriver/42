/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 13:20:36 by amathias          #+#    #+#             */
/*   Updated: 2016/02/03 11:52:06 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char		*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return ((char*)&str[i]);
		i++;
	}
	if (str[i] == c)
		return ((char*)&str[i]);
	return (NULL);
}

static int	ft_intlen_base(long n, int base)
{
	int i;

	i = 1;
	if (n < 0 && base == 10)
		i++;
	while (n > base - 1 || (n < -9 && base == 10))
	{
		i++;
		n = n / base;
	}
	return (i);
}

char	*ft_itoa_base(long n, int base)
{
	char	*tmp;
	long	ntmp;
	int		len;
	int		i;

	len = ft_intlen_base(n, base);
	if ((tmp = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (n < 0 && base == 10)
		tmp[0] = '-';
	i = len - 1;
	tmp[len] = '\0';
	while (n != 0)
	{
		ntmp = n > 0 ? (n % base) : -(n % base);
		tmp[i] = ntmp > 9 ? ((ntmp - 10) + 'A') : (ntmp + '0');
		i--;
		n = n / base;
	}
	return (tmp);
}
