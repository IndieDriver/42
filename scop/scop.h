/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 13:49:36 by amathias          #+#    #+#             */
/*   Updated: 2016/09/15 18:03:52 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include "mlx.h"
# include "mlx_opengl.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <OpenGL/gl3.h>
# include <math.h>

typedef float		t_mat4[16];

typedef struct		s_vec2
{
	float			x;
	float			y;
}					t_vec2;

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef	struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef	struct		s_obj
{
	t_list			*vertex;
	t_list			*tri;
}					t_obj;

typedef struct		s_cam
{
	t_vec4			pos;
	t_vec4			dir;
	t_vec4			right;
}					t_cam;

typedef struct		s_key
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				q;
	int				e;
	int				rup;
	int				rdown;
	int				rleft;
	int				rright;
	int				rshift;
	int				rcontrol;
	int				kspace;
	int				r;
}					t_key;

typedef struct		s_bmp
{
	unsigned int	data_start;
	unsigned int	img_size;
	unsigned int	width;
	unsigned int	height;
	char			*data;
}					t_bmp;

typedef struct		s_map
{
	void			*mlx;
	void			*win;
	t_cam			cam;
	t_key			key;
	t_vec4			pos;
	t_vec4			init_pos;
	t_vec4			rot;
	int				has_texture;
	int				nb_vertex;
	t_vec3			*vertex_array;
	t_vec3			*normal_array;
	t_vec2			*uv_array;
	int				nb_indice;
	unsigned int	*indice_array;
	GLuint			program_id;
	t_mat4			modelmat4;
	GLuint			modelmat4_id;
	t_mat4			viewmat4;
	GLuint			viewmat4_id;
	t_mat4			projmat4;
	GLuint			projmat4_id;
	t_mat4			mvpmat4;
	GLuint			mvpmat4_id;
	t_mat4			normalmat4;
	GLuint			normalmat4_id;
	GLuint			texture_id;
}					t_map;

void				move(t_map *map);
void				draw(t_map *map);

void				parse_obj_file(char *file_name, t_map *map);
double				ft_atoi_double(char *str);
t_vec3				get_vec(char **line_split);
t_vec4				get_vec_4(char **line_split);
int					is_split_valid(char **line_split, int size);
void				obj_reconstruct(t_map *map);
void				obj_reconstruct_indice(t_obj *obj, t_map *map);
int					count_tri(t_list *elem, int max_vertex);
int					count_vertex(t_list *elem);
void				obj_delete_link(void *ptr, size_t size);

t_bmp				parse_bmp(char *filename);

void				get_projmatrix(t_mat4 mat, float fov, float ratio);
void				get_viewmatrix(t_map *map, t_vec4 pos,
					t_vec4 center, t_vec4 up);
void				apply_trans(t_mat4 in, t_vec4 trans, t_vec4 rot);
void				get_mvp(t_mat4 out, t_mat4 m, t_mat4 v, t_mat4 p);
void				get_normalmat(t_mat4 out, t_mat4 m, t_mat4 v);

t_vec3				get_vec3(float x, float y, float z);
t_vec4				get_vec4(float x, float y, float z, float w);
t_vec4				vec3tovec4(t_vec3 vec3);
int					vec4cmp(t_vec4 v1, t_vec4 v2);
t_vec4				neg_vec4(t_vec4 vec);
t_vec4				vec_cross(t_vec4 v1, t_vec4 v2);
void				vec_normalize(t_vec4 *v1);
double				vec_len(t_vec4 vec);
t_vec4				vec_sub(t_vec4 v1, t_vec4 v2);
t_vec4				vec_mul(t_vec4 v1, t_vec4 v2);
t_vec4				vec_add(t_vec4 v1, t_vec4 v2);
t_vec4				vec_scale(t_vec4 v1, float fact);
double				dot(t_vec4 v1, t_vec4 v2);

void				print_matrix(t_mat4 mat);
void				cpy_mat4(t_mat4 src, t_mat4 dest);
void				mat4_mul(t_mat4 result, t_mat4 m1, t_mat4 m2);
void				get_identity_mat4(t_mat4 mat);
t_vec4				mul_matrix4_vec4(t_mat4 mat, t_vec4 vec4);
t_vec4				trans_matrix_vec4(t_vec4 pos, t_vec4 trans);
t_vec4				rot_matrix_vec4(t_vec4 pos, t_vec4 rot);
void				get_translation_matrix(t_mat4 mat,
						float x, float y, float z);
void				get_rot_matrix(t_mat4 m,
						float rot_x, float rot_y, float rot_z);
void				transpose(t_mat4 out);

int					loop_hook(t_map *map);
int					expose_hook(t_map *map);
int					red_cross(t_map *map);
int					key_hook(int keycode, t_map *map);
int					key_press(int keycode, t_map *map);
GLuint				load_shaders(char *vertex_file_name,
						char *fragment_file_name);
void				set_normal_array(t_map *map);
void				set_uv_array(t_map *map);
#endif
