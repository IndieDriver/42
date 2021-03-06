/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:28:49 by amathias          #+#    #+#             */
/*   Updated: 2016/03/20 15:57:53 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <pthread.h>
# include "libft.h"
# define WIDTH 1440
# define HEIGHT 960
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

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_line;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			color;
}				t_pos;

typedef struct	s_dda
{
	double		dx;
	double		dy;
	int			sx;
	int			sy;
	int			side;
	t_pos		pos;
}				t_dda;

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_tex
{
	int			id;
	double		wallcord;
	int			x;
}				t_tex;

typedef struct	s_key
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			mleft;
	int			mright;
}				t_key;

typedef struct	s_map
{
	t_env		env;
	t_img		img;
	t_img		mmap;
	int			multithread;
	int			type;
	int			pause;
	int			**grid;
	int			height;
	int			width;
	t_tex		texvalue;
	int			***tex;
	t_key		key;
	t_vec		pos;
	t_vec		dirvec;
	t_vec		cvec;
}				t_map;

typedef struct	s_args
{
	t_map		*m;
	t_pos		min;
	t_pos		max;
}				t_args;

void			draw(t_map *map);
int				get_hex_color(t_map *map, int x, int y);
t_pos			get_pos(int x, int y);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

int				expose_hook(t_map *map);
int				key_press(int keycode, t_map *map);
int				key_hook(int keycode, t_map *map);
void			init_key(t_map *map);
int				loop_hook(t_map *map);

void			rotate(t_map *map);
void			move(t_map *map);

void			ray(t_args *args);
void			draw_wall_slice(t_map *map, t_pos pos, t_tex tex);
void			draw_line(t_map *map, t_pos from, t_pos to, int color);
int				**get_texture(char *file_name, int size);

int				**get_grid(t_map *map, char *file_name);

int				***init_tex_array(int nb);
void			free_tex_array(int ***tex_array, int nb);
void			draw_tex(t_map *map, t_pos from, t_pos to, t_tex tex);

t_args			*init_thread(t_map *map, t_pos min, t_pos max);
void			multi_thread(t_map *map, void *function);

void			pause_on(t_map *map);
#endif
