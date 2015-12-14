/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:48:16 by amathias          #+#    #+#             */
/*   Updated: 2015/12/14 15:00:54 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_tetri
{
	t_pos		tab[4];
	int			index;
}				t_tetri;

t_tetri			*ft_inittetriminos();
int				ft_isvalid(const char *str);
int				ft_addtetri(t_tetri *list, char *str);

int				**ft_initgrid(int size);
void			ft_printgrid(int **grid, int size);
void			ft_freegrid(int	**grid, int size);

void			ft_solve(t_tetri *list);

int				ft_nextvalid(int **grid, int size, t_tetri tetri, int pos);
void			ft_placetetri(int **grid, int size, t_tetri tetri, int pos);
void			ft_removetetri(int **grid, int size, t_tetri tetri, int pos);
#endif
