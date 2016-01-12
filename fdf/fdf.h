/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:24:11 by amathias          #+#    #+#             */
/*   Updated: 2016/01/12 16:43:06 by amathias         ###   ########.fr       */
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
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_rect
{
	t_point 	tl;
	t_point 	tr;
	t_point 	bl;
	t_point 	br;
}				t_rect;

typedef struct	s_map
{
	int			width;
	int			height;
	t_env		env;
	t_img		img;
	t_rect		*rect;
	t_point		**grid;
}				t_map;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_line;


t_map			*get_map(char *filename);

t_point			setpoint(int x, int y, int z, int color);
t_point			convertcord(t_point point);
void			draw_iso(t_map *map, t_point **grid, int row, int col);
t_map			*adapt_grid(t_map *map);

void			draw_line(t_map *map, t_point from, t_point to);

void			print_grid(t_map *map);
void			ft_error(void);

void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

void			fill_rect(t_map *map, int x, int y, int color);
t_rect			*init_rectlist(t_map *map);
void			save_rect(t_map *map, t_rect rect);
#endif
