/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emontagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 11:36:38 by emontagn          #+#    #+#             */
/*   Updated: 2016/01/31 12:27:30 by emontagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_map_chars(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(CHARS, map[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int		check_map_borders(char **map)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = ft_arrsize(map) - 1;
	while (i <= size)
	{
		if (i == 0 || i == size)
		{
			j = 0;
			while (j <= size)
			{
				if (map[i][j] != '1')
					return (FALSE);
				j++;
			}
		}
		else if (map[i][0] != '1' || map[i][size] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		check_map_lines(char **map)
{
	int		i;
	int		len;
	int		size;

	size = ft_arrsize(map);
	if (size < 3)
		return (FALSE);
	len = ft_strlen(map[0]);
	if (len < 3 || len != size)
		return (FALSE);
	i = 1;
	while (map[i])
	{
		if (len != ft_strlen(map[i]) || ft_strlen(map[i]) < 3 || len != size)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
