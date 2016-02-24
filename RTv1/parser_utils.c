/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:27 by amathias          #+#    #+#             */
/*   Updated: 2016/02/24 17:08:19 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "shape.h"

double	ft_atoi_double(char *str)
{
	double	in;
	double	ret;

	in = ft_atoi(str);
	str = ft_strchr(str, '.') + 1;
	ret = ft_atoi(str);
	while (ret >= 1.0)
		ret = ret / 10.0;
	return (in + ret);
}

int    ft_atoi_hex(char *line)
{
	int    nbr;
	int    i;
	int    add;

	i = 0;
	nbr = 0;
	if (ft_strlen(line) == 0)
		ft_parse_error(6);
	while ((line[i] >= '0' && line[i] <= '9')
			|| (line[i] >= 'A' && line[i] <= 'F'))
	{
		if (line[i] > '9')
			add = 9 + line[i] - 'A' + 1;
		else
			add = line[i] - '0';
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
					break;
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
