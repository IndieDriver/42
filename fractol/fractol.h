/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:59:32 by amathias          #+#    #+#             */
/*   Updated: 2016/02/20 16:33:19 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include "libft.h"
# define WIDTH 1000
# define HEIGHT 1000

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
	int			iterplus;
	int			iterminus;
}				t_key;

typedef struct	s_complex
{
	double		real;
	double		ima;
}				t_complex;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_line;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_map
{
	t_env		env;
	t_img		img;
	int			type;
	double		zoom;
	double		mx;
	double		my;
	int			max_iter;
	t_complex	c;
	t_point		**grid;
	int			zoffset;
	int			iso;
	t_key		key;
}				t_map;

typedef struct	s_args
{
	t_map		*map;
	t_point		min;
	t_point		max;
}				t_args;

void			draw(t_map *map);
void			draw_fractal(t_map *map);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

int				expose_hook(t_map *map);
int				motion_notify(int x, int y, t_map *map);
int				key_press(int keycode, t_map *map);
int				loop_hook(t_map *map);
int				key_hook(int keycode, t_map *map);
int				mouse_hook(int keycode, int x, int y, t_map *map);

void			draw_julia(void	*args);
void			draw_mandelbrot(void *args);
void			draw_burning(void *args);
void			draw_rabbit(void *args);
void			draw_siegel(void *args);
void			draw_amathias(void *args);

int				*init_mandelbrot_color(int max_iter);
int				*init_julia_color(int max_iter);
int				*init_burning_color(int max_iter);

void			init_key(t_map *map);
void			zoom(t_map *map);
void			move(t_map *map);

void			multi_thread(t_map *map, void *function);
int				get_color(int iter);

void			init_grid(t_map *map);
void			free_grid(t_map *map);

void			ft_error(int type);

int				fdf_init(t_map *map);
t_point			setpoint(int x, int y, int z, int color);
t_point			convertcord(t_point point);
void			draw_iso(t_map *map, t_point **grid, int row, int col);
void			draw_line(t_map *map, t_point from, t_point to, int color);
#endif
