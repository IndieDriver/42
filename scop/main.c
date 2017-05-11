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

/*
t_vec4	get_shared_normal(t_map *map, t_vec4 pt)
{
	int		i;
	t_vec4	pt1;
	t_vec4	pt2;
	t_vec4	pt3;
	t_vec4	nor;

	i = 0;
	nor = get_vec4(0.0f, 0.0f, 0.0f, 0.0f);
	while (i < map->nb_tri * 3)
	{
		pt1 = get_vec4(map->tri_list[i], map->tri_list[i + 1],
			map->tri_list[i + 2], 0.0f);
		pt2 = get_vec4(map->tri_list[i + 3], map->tri_list[i + 4],
			map->tri_list[i + 5], 0.0f);
		pt3 = get_vec4(map->tri_list[i + 6], map->tri_list[i + 7],
			map->tri_list[i + 8], 0.0f);
		if (vec4cmp(pt, pt1) || vec4cmp(pt, pt2) || vec4cmp(pt, pt3))
			nor = vec_add(nor, get_normal_tri(pt1, pt2, pt3));
		i += 9;
	}
	return (nor);
}

float	*get_normal_list(t_map *map)
{
	float	*list;
	int		i;
	int		j;
	t_vec4	nor;

	i = 0;
	list = (float*)malloc(sizeof(float) * map->nb_tri * 3);
	map->uv_list = (float*)malloc(sizeof(float) * map->nb_tri * 5);
	while (i < map->nb_tri * 3)
	{
		nor = get_shared_normal(map, get_vec4(map->tri_list[i],
			map->tri_list[i + 1], map->tri_list[i + 2], 0.0f));
		vec_normalize(&nor);
		list[i + 0] = nor.x;
		list[i + 1] = nor.y;
		list[i + 2] = nor.z;
		i += 3;
	}
	i = 0;
	j = 0;
	while (i < map->nb_tri)
	{
		map->uv_list[j + 0] = 0.0f;
		map->uv_list[j + 1] = 0.0f;
		map->uv_list[j + 2] = 1.0f;
		map->uv_list[j + 3] = 1.0f;
		map->uv_list[j + 4] = 1.0f;
		map->uv_list[j + 5] = 0.0f;
		j += 5;
		i++;
	}
	return (list);
} */

void	get_normal_array(t_map *map)
{
	float	*normal_array;
	int		i;

	i = 0;
	normal_array = (float*)malloc(sizeof(float) * map->nb_vertex * 3);
	while (i < map->nb_vertex) {
		normal_array[i + 0] = 1.0f;
		normal_array[i + 1] = 0.0f;
		normal_array[i + 2] = 0.0f;
		i += 3;
	}
	map->normal_list = normal_array;
}

void	init_texture(t_map *map, t_bmp bmp)
{
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
	//map.normal_list = get_normal_list(&map);
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
