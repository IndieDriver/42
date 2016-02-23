/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:27:27 by amathias          #+#    #+#             */
/*   Updated: 2016/02/23 16:44:04 by amathias         ###   ########.fr       */
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
