/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:29:10 by amathias          #+#    #+#             */
/*   Updated: 2016/02/26 02:02:00 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
#include <stdio.h>
# include "shape.h"
# include "libft.h"
# define WIDTH 720
# define HEIGHT 480
# define RED  "\x1B[31m"
# define WHT  "\x1B[37m"
# define RST "\033[0m"

typedef struct 	s_env
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

typedef struct 	s_pos
{
	int			x;
	int			y;
	int			color;
}				t_pos;
/*
typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;
*/
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
	t_scene		scene;
	t_img		img;
	t_key		key;
	t_vec		pos;
	t_vec		dirvec;
	t_vec		cvec;
}				t_map;

void			draw(t_map *map);
int				get_hex_color(t_map *map, int x, int y);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

int				expose_hook(t_map *map);
int				key_press(int keycode, t_map *map);
int				key_hook(int keycode, t_map *map);
void			init_key(t_map *map);
int				loop_hook(t_map *map);

void			raytracer(t_map *map);

void			parse_file(t_map *map, char *file_name);

void			process_scene(char **line_split, int type, t_scene *scene);

void			get_scene(char **file, t_scene *scene, int line);
void			get_object(char **file, t_scene *scene, int line);

t_sphere		*get_sphere(char **file, int line);
t_plan			*get_plan(char **file, int line);
t_cone			*get_cone(char **file, int line);
t_cylinder		*get_cylinder(char **file, int line);

char			**get_file(char *file_name);
int				is_line_split_valid(char **line_split, int nb);
int				ft_atoi_hex(char *line);
double			ft_atoi_double(char *str);
int				contain(char *str, char *str2);
void			ft_parse_error(int type);
#endif
