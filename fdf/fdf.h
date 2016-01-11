/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:24:11 by amathias          #+#    #+#             */
/*   Updated: 2016/01/11 15:04:39 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
#include <stdio.h>
# include "libft.h"
# define HEIGHT 1000
# define WIDTH	1000

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

typedef struct	s_rect
{
	t_point tl;
	t_point tr;
	t_point bl;
	t_point br;
}				t_rect;

t_map			*get_map(char *filename);

t_point			setpoint(int x, int y, int z, char color[10]);
t_point			convertcord(t_point point);
void			draw_iso(t_env env, t_point **grid, int row, int col);
t_map			*adapt_grid(t_map *map);

void			draw_line(t_env env, t_point from, t_point to);

void	print_grid(t_map *map);
void			ft_error(void);

void			fill_rect(t_env env, t_rect rect);
#endif
