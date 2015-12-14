/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:21:39 by amathias          #+#    #+#             */
/*   Updated: 2015/12/09 10:45:49 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printgrid(int **grid, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (grid[i][j] == -1)
				ft_putchar('.');
			else
				ft_putchar('A' + grid[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_freegrid(int **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(grid[i]);
		++i;
	}
	free(grid);
}

int		**ft_initgrid(int size)
{
	int i;
	int j;
	int **grid;

	i = 0;
	if (!(grid = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(grid[i] = (int*)malloc(sizeof(int) * size)))
			return (NULL);
		j = 0;
		while (j < size)
		{
			grid[i][j] = -1;
			++j;
		}
		++i;
	}
	return (grid);
}
