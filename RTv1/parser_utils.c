/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:27 by amathias          #+#    #+#             */
/*   Updated: 2016/03/30 15:57:29 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_atoi_double(char *str)
{
	double	in;
	double	ret;
	double	sign;

	sign = 1.0;
	in = ft_atoi(str);
	if (ft_strchr(str, '-'))
		sign = -1.0;
	in = fabs(in);
	if (!ft_strchr(str, '.'))
		return (in);
	str = ft_strchr(str, '.') + 1;
	ret = ft_atoi(str);
	while (ret >= 1.0)
		ret = ret / 10.0;
	in = (sign * (in + ret));
	if (in != in)
		return (0.0);
	return (in);
}

int		ft_atoi_hex(char *line)
{
	int		nbr;
	int		i;
	int		add;

	i = -1;
	nbr = 0;
	while (line[i++])
		line[i] = ft_toupper(line[i]);
	i = 0;
	if (ft_strlen(line) == 0)
		ft_parse_error(6, -1);
	while ((line[i] >= '0' && line[i] <= '9')
			|| (line[i] >= 'A' && line[i] <= 'F'))
	{
		add = line[i] > '9' ? 9 + line[i] - 'A' + 1 : line[i] - '0';
		nbr = nbr * 16 + add;
		i++;
	}
	return (nbr);
}

int		contain(char *str, char *str2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (str[i] && str2[j])
	{
		if (str[i] == str2[j])
		{
			k = i;
			while (str[k] && str2[j])
			{
				if (str[k] != str2[j])
					break ;
				j++;
				k++;
			}
			if ((size_t)j == ft_strlen(str2))
				return (1);
			j = 0;
		}
		i++;
	}
	return (0);
}
