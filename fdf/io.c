/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:43:39 by amathias          #+#    #+#             */
/*   Updated: 2016/01/04 14:00:41 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_initgrid(int row, int column)
{
	int i;
	int j;
	int **grid;

	i = 0;
	if(!(grid = (int**)malloc(sizeof(int*) * size)))
		return (NULL);
	while (i < row)
	{
		if (!(grid[i] = (int*)malloc(sizeof(int) * column)))
			return (NULL);
		j = 0;
		while (j < column)
		{
			grid[i][j] = -1;
			j++;
		}
		i++;
	}
	return (grid);
}

int		get_number_of_row(char *file_name)
{
	int fd;
	char *line;
	int lnb;

	lnb = 0;
	if ((fd = open(filename, O_RDONLY)))
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		lnb++;
	}
	if (clode(fd) == -1)
		return (-1);
	return (lnb);
}

int		get_number_of_col(char *file_name)
{
	int fd;
	char *line;
	int lcol;

	lcol = 0;
	if ((fd = open(filename, O_RDONLY)))
		return (-1);
	get_next_line(fd, &line);
	ft_strplit(line, ' ');
	free(line);
}

void	add_line(int **grid)
{
	int i;
	
}

int		**read_file(char *file_name)
{
	int fd;
	char *line;
	int **grid;
	int i;

	i = 0;
	grid = ft_initgrid(get_number_of_line(file_name));
	if ((fd = open(filename, O_RDONLY)))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		
		free(line);
	}
	if (close(fd) == -1)
		return (NULL);
}
