/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:38:52 by amathias          #+#    #+#             */
/*   Updated: 2015/12/14 14:59:50 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_backtrack(int **grid, t_tetri *tetri, int size)
{
	int i;
	int pos;

	i = 0;
	pos = 0;
	if (tetri->tab[0].x == -1)
		return (1);
	while ((pos = ft_nextvalid(grid, size, *tetri, pos)) != -1)
	{
		ft_placetetri(grid, size, *tetri, pos);
		if (ft_backtrack(grid, tetri + 1, size))
			return (1);
		ft_removetetri(grid, size, *tetri, pos);
		++pos;
	}
	return (0);
}

void		ft_solve(t_tetri *list)
{
	int **grid;
	int size;

	size = 2;
	grid = ft_initgrid(size);
	if (grid)
	{
		while (ft_backtrack(grid, &list[0], size) == 0)
		{
			ft_freegrid(grid, size);
			++size;
			grid = ft_initgrid(size);
		}
		ft_printgrid(grid, size);
		ft_freegrid(grid, size);
	}
}
