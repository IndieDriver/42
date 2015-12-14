/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:29:26 by amathias          #+#    #+#             */
/*   Updated: 2015/12/14 15:00:58 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_placetetri(int **grid, int size, t_tetri tetri, int pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[((pos / size)) + (tetri.tab[i].y)]
			[((pos % size)) + (tetri.tab[i].x)] = tetri.index;
		++i;
	}
}

void		ft_removetetri(int **grid, int size, t_tetri tetri, int pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		grid[((pos / size)) + (tetri.tab[i].y)]
			[((pos % size)) + (tetri.tab[i].x)] = -1;
		++i;
	}
}

static int	ft_outofbound(t_tetri tetri, int size, int pos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetri.tab[i].y + (pos / size) >= size
				|| tetri.tab[i].x + (pos % size) >= size
				|| tetri.tab[i].y + (pos / size) < 0
				|| tetri.tab[i].x + (pos % size) < 0)
			return (1);
		++i;
	}
	return (0);
}

static int	ft_istetrivalid(int **grid, int size, t_tetri tetri, int pos)
{
	int i;
	int isvalid;

	i = 0;
	isvalid = 1;
	if (grid[pos / size][pos % size] == -1 && !ft_outofbound(tetri, size, pos))
	{
		while (i < 4)
		{
			if (grid[(pos / size) + (tetri.tab[i].y)]
					[(pos % size) + (tetri.tab[i].x)] != -1)
				return (0);
			++i;
		}
		return (1);
	}
	return (0);
}

int		ft_nextvalid(int **grid, int size, t_tetri tetri, int pos)
{
	if (pos == size * size)
		return (-1);
	if (ft_istetrivalid(grid, size, tetri, pos))
		return (pos);
	return (ft_nextvalid(grid, size, tetri, pos + 1));
}
