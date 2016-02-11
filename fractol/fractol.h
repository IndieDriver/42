/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:59:32 by amathias          #+#    #+#             */
/*   Updated: 2016/02/11 14:12:05 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
#include <stdio.h>
# include "libft.h"
# define WIDTH 1000
# define HEIGHT 1000
# include "libft.h"

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

typedef struct	s_key
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			mdown;
	int			mup;
}				t_key;

typedef struct	s_complex
{
	double		real;
	double		ima;
}				t_complex;

typedef struct	s_map
{
	t_env		env;
	t_img		img;
	int			type;
	double		zoom;
	int			pow;
	double		mx;
	double		my;
	t_complex	c;
	t_key		key;
}				t_map;

void			draw(t_map *map);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

int				expose_hook(t_map *map);
int				motion_notify(int x, int y, t_map *map);
int				key_press(int keycode, t_map *map);
int				loop_hook(t_map *map);
int				key_hook(int keycode, t_map *map);

void			draw_julia(t_map *map, int max_iter);
void			draw_mandelbrot(t_map *map, int max_iter, int *color_array);
void			draw_burning(t_map *map, int max_iter, int *color_array);

int				*init_mandelbrot_color(int max_iter);
int				*init_julia_color(int max_iter);
int				*init_burning_color(int max_iter);

void			zoom(t_map *map);
void			move(t_map *map);
#endif
