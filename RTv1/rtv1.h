/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:29:10 by amathias          #+#    #+#             */
/*   Updated: 2016/03/22 11:27:30 by amathias         ###   ########.fr       */
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

typedef struct 	s_pos
{
	int			x;
	int			y;
	int			color;
}				t_pos;

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
void			move(t_map *map);

int				expose_hook(t_map *map);
int				key_press(int keycode, t_map *map);
int				key_hook(int keycode, t_map *map);
void			init_key(t_map *map);
int				loop_hook(t_map *map);

void			raytracer(t_map *map);

double			getdist_sph(t_sphere s, t_vec ray, t_vec opos);
double			getdist_plan(t_plan p, t_vec ray, t_vec opos);
double			getdist_cyl(t_cylinder *cyl, t_vec ray, t_vec opos);
double			getdist_cone(t_cone *cone, t_vec ray, t_vec opos);

t_vec			get_normal(void *shape, t_vec inter);

void			*iter(t_map *map, t_vec ray, t_vec opos);

void			*get_nearest(t_sphere *sph, t_plan *plan, t_cylinder *cyl,
					t_cone *cone);

int				get_color(void *shape, t_vec inter, t_vec light, int color);
int				light_rgb(int rgb, double angle);

t_vec			ray_viewplane(t_map *map, int x, int y);
t_vec			ray_invlight(t_vec inter, t_vec light_pos);
t_vec			ray_light(t_vec inter, t_vec light_pos);
t_vec			ray_inter(t_vec ray, t_vec opos, double t);
t_vec			ray_shadow(t_map *map, t_vec inter, double offset_x,
				double offset_y);

void			vec_normalize(t_vec *vec);
double			vec_dotproduct(t_vec v1, t_vec v2);
t_vec			vec_sub(t_vec v1, t_vec v2);
t_vec			vec_multbyscalar(t_vec vec, double sca);
t_vec			vec_project(t_vec v1, t_vec v2);

int				get_shadow_color(int color, int nb);
int				get_shadow(t_map *map, void *shape, t_vec inter, int color);

int				get_reflection(t_map *map, void *shape, t_vec light,
				t_vec inter, int color);

void			parse_file(t_map *map, char *file_name);
void			process_scene(char **line_split, int type,
					t_scene *scene, int line);

void			get_scene(char **file, t_scene *scene, int line);
void			get_object(char **file, t_scene *scene, int line);
void			get_vec_list(t_scene *scene, char **file, int line);

t_sphere		get_sphere(char **file, int line);
t_plan			get_plan(char **file, int line);
t_cone			get_cone(char **file, int line);
t_cylinder		get_cylinder(char **file, int line);

t_vec			get_vec(char **line_split, int type, int line);
char			**get_file(char *file_name);
int				is_line_split_valid(char **line_split, int nb);
int				ft_atoi_hex(char *line);
double			ft_atoi_double(char *str);
int				contain(char *str, char *str2);
void			ft_parse_error(int type, int line);
#endif
