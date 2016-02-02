/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:24:11 by amathias          #+#    #+#             */
/*   Updated: 2016/02/02 14:29:26 by amathias         ###   ########.fr       */
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

typedef struct	s_map
{
	int			width;
	int			height;
	t_env		env;
	t_img		img;
	t_point		**grid;
	t_point		**cart;
	int		zoffset;
}				t_map;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_line;

typedef struct s_rgb
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}				t_rgb;

t_map			*get_map(char *filename);
void			free_map(t_map *map);

t_point			setpoint(int x, int y, int z, int color);
t_point			convertcord(t_point point);
void			draw_iso(t_map *map, t_point **grid, int row, int col);
t_map			*adapt_grid(t_map *map);

void			draw_line(t_map *map, t_point from, t_point to, int color);

void			draw(t_map *map);
void			shift_grid(t_map *map);
void			ft_error(void);

int				get_color(int i);
int				get_hex_color(t_map *map, int x, int y);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

t_point			**copy_grid(t_map *map, t_point **src);

int				expose_hook(t_map *map);
int				key_hook(int keycode, t_map *map);
#endif
