/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:24:11 by amathias          #+#    #+#             */
/*   Updated: 2016/01/10 16:28:23 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
#include <stdio.h>
# include "libft.h"
# define HEIGHT 680
# define WIDTH	480

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
}		t_env;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
	char	color[10];
}		t_point;

typedef struct	s_map
{
	int	width;
	int	height;
	t_env	env;
	t_point	**grid;
}		t_map;


typedef struct	s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}		t_line;

t_map			*get_map(char *filename);

t_point			setpoint(int x, int y, int z, char color[10]);
t_point			convertcord(int x, int y);
void			draw_iso(t_env env, t_point **grid, int row, int col);

void			draw_line(t_env env, t_point from, t_point to);

void			ft_error(void);
#endif
