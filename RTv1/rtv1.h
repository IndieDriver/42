/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:29:10 by amathias          #+#    #+#             */
/*   Updated: 2016/03/30 15:57:03 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "shape.h"
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

typedef struct	s_map
{
	t_env		env;
	t_scene		scene;
	t_img		img;
}				t_map;

void			draw(t_map *map);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

int				expose_hook(t_map *map);
int				key_hook(int keycode, t_map *map);
int				red_cross(t_map *map);

void			raytracer(t_map *map);
double			getdist_sph(t_sphere s, t_vec ray, t_vec opos);
double			getdist_plan(t_plan p, t_vec ray, t_vec opos);
double			getdist_cyl(t_cylinder *cyl, t_vec ray, t_vec opos, int n);
double			getdist_cone(t_cone *cone, t_vec ray, t_vec opos, int n);

t_vec			get_normal(void *shape, t_vec inter);

void			*iter(t_map *map, t_vec ray, t_vec opos, int get_normal);

void			*get_nearest(t_sphere *s, t_plan *p, t_cylinder *cy, t_cone *c);

double			get_diffuse(void *shape, t_vec light);
double			get_spec(void *shape, t_vec light, t_vec eye);

t_vec			ray_viewplane(t_map *map, int x, int y);
t_vec			ray_invlight(t_vec inter, t_vec light_pos);
t_vec			ray_light(t_vec inter, t_vec light_pos);
t_vec			ray_inter(t_vec ray, t_vec opos, double t);

void			vec_normalize(t_vec *vec);
double			vec_dot(t_vec v1, t_vec v2);
t_vec			vec_sub(t_vec v1, t_vec v2);

int				col_add(int c1, int c2);
int				col_add_array(int ambient, int *c, int nb);
int				col_mul(int c1, double mul);

int				get_shadow_color(int color, int nb);
int				get_shadow(int color);

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

void			init_t_sphere(t_sphere *sph);
void			init_t_plan(t_plan *plan);
void			init_t_cylinder(t_cylinder *cyl);
void			init_t_cone(t_cone *cone);

void			ft_error(t_map *map, int w);
t_vec			get_vec(char **line_split, int type, int line);
char			**get_file(char *file_name);
int				is_line_split_valid(char **line_split, int nb);
double			to_rad(double deg);
int				ft_atoi_hex(char *line);
double			ft_atoi_double(char *str);
int				contain(char *str, char *str2);
void			ft_parse_error(int type, int line);
#endif
