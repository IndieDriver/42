/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 13:31:16 by amathias          #+#    #+#             */
/*   Updated: 2016/09/30 13:33:39 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_cam(t_map *map)
{
	apply_trans(map->modelmat4, map->pos, map->rot);
	get_viewmatrix(map, get_vec4(0.0f, 0.0f, -1.0f, 0.0f),
						get_vec4(0.0f, 0.0f, 0.0f, 0.0f),
						get_vec4(0.0f, 1.0f, 0.0f, 0.0f));
	get_projmatrix(map->projmat4, 45.0f, 1080.0f / 720.0f);
	get_mvp(map->mvpmat4, map->modelmat4, map->viewmat4, map->projmat4);
	get_normalmat(map->normalmat4, map->modelmat4, map->viewmat4);
}

t_vec4	get_normal_tri(t_vec4 pt1, t_vec4 pt2, t_vec4 pt3)
{
	t_vec4 nor;

	nor = vec_cross(vec_sub(pt2, pt1), vec_sub(pt3, pt1));
	vec_normalize(&nor);
	return (nor);
}

void	add_normal(t_map *map, t_vec4 normal, int indice_index)
{
	t_vec4 tmp;

	vec_normalize(&normal);
	tmp = vec3tovec4(map->normal_array[map->indice_array[indice_index]]);
	tmp = vec_add(normal, tmp);
	vec_normalize(&tmp);
	map->normal_array[map->indice_array[indice_index]].x = tmp.x;
	map->normal_array[map->indice_array[indice_index]].y = tmp.y;
	map->normal_array[map->indice_array[indice_index]].z = tmp.z;
}


t_vec4	get_normal(t_map *map, int indice_index)
{
	t_vec3 pt1;
	t_vec3 pt2;
	t_vec3 pt3;
	t_vec4 normal;

	pt1 = map->vertex_array[map->indice_array[indice_index]];
	pt2 = map->vertex_array[map->indice_array[indice_index + 1]];
	pt3 = map->vertex_array[map->indice_array[indice_index + 2]];
	normal = get_normal_tri(vec3tovec4(pt1), vec3tovec4(pt2), vec3tovec4(pt3));
	return (normal);
}

void	get_shared_normal(t_map *map)
{
	t_vec4 nor;
	int i;

	i = 0;
	nor = get_vec4(0.0f, 0.0f, 0.0f, 0.0f);
	while (i < map->nb_indice)
	{
		nor = get_normal(map, i);
		vec_normalize(&nor);
		add_normal(map, nor, i);
		add_normal(map, nor, i + 1);
		add_normal(map, nor, i + 2);
		i += 3;
	}
	printf("i: %d\n", i);
}

void	get_normal_array(t_map *map)
{
	t_vec3	*normal_array;
	t_vec2	*uv_array;
	int		i;

	i = 0;
	normal_array = (t_vec3*)malloc(sizeof(t_vec3) * map->nb_vertex);
	uv_array = (t_vec2*)malloc(sizeof(t_vec2) * map->nb_vertex);
	while (i < map->nb_vertex / 3)
	{
		normal_array[i].x = 0.0f;
		normal_array[i].y = 0.0f;
		normal_array[i].z = 0.0f;
		uv_array[i].x = 0.0f;
		uv_array[i].y = 0.0f;
		i++;
	}
	map->normal_array = normal_array;
	map->uv_array = uv_array;
	get_shared_normal(map);
}

void	init_texture(t_map *map, t_bmp bmp)
{
	map->has_texture = 1;
	glGenTextures(1, &map->texture_id);
	glBindTexture(GL_TEXTURE_2D, map->texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp.width, bmp.height, 0, GL_BGR,
		GL_UNSIGNED_BYTE, bmp.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

int		main(int argc, char **argv)
{
	t_map	map;
	t_bmp	bmp;

	if (argc != 2)
		exit(0);
	parse_obj_file(argv[1], &map);
	get_normal_array(&map);
	map.pos = get_vec4(0.0f, 0.0f, 30.0f, 0.0f);
	map.rot = get_vec4(0.0f, 0.0f, 0.0f, 0.0f);
	map.mlx = mlx_init();
	map.win = mlx_new_opengl_window(map.mlx, 1080, 720, "scop");
	mlx_opengl_window_set_context(map.win);
	map.program_id = load_shaders("tri_vs.glsl", "tri_fs.glsl");
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	bmp = parse_bmp("texture.bmp");
	init_texture(&map, bmp);
	init_cam(&map);
	init_key(&map);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_hook(map.win, 2, (1L << 0), key_press, &map);
	mlx_hook(map.win, 17, (1L << 17), red_cross, &map);
	mlx_expose_hook(map.win, expose_hook, &map);
	mlx_loop_hook(map.mlx, loop_hook, &map);
	mlx_loop(map.mlx);
}
