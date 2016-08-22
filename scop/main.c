/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 13:31:16 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 17:28:33 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
void	test(t_map *map)
{
	GLuint vbo = 0;
	GLuint vao = 0;
	float points[] = {
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), points, GL_STATIC_DRAW);
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(map->program_id);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	mlx_opengl_swap_buffers(map->win);
} */

void	init_cam(t_map *map)
{
	apply_trans(map->modelmat4, map->pos, map->rot);	
	get_viewmatrix(map,
			get_vec4(0.0f, 0.0f, -1.0f, 0.0f),
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

t_vec4	get_shared_normal(t_map *map, t_vec4 pt)
{
	int i;
	t_vec4 pt1;
	t_vec4 pt2;
	t_vec4 pt3;
	t_vec4 nor;

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
		if (is_vec4equal(pt, pt1) || is_vec4equal(pt, pt2)
			|| is_vec4equal(pt, pt3))
			nor = vec_add(nor, get_normal_tri(pt1, pt2, pt3));
		i+=9;
	}
	return (nor);
}

float	*get_normal_list(t_map *map)
{
	float	*list;
	int		i;
	t_vec4	nor;

	i = 0;
	list = (float*)malloc(sizeof(float) * map->nb_tri * 3);
	while (i < map->nb_tri * 3)
	{
		nor = get_shared_normal(map, get_vec4(map->tri_list[i],
			map->tri_list[i + 1], map->tri_list[i + 2], 0.0f));
		vec_normalize(&nor);
		list[i + 0] = nor.x;
		list[i + 1] = nor.y;
		list[i + 2] = nor.z;
		i+= 3;
	}
	return (list);
}

int		main(int argc, char **argv)
{
	t_map map;

	(void)argc;
	(void)argv;
	if (argc != 2)
		exit(0);
	map.tri_list = parse_obj_file(argv[1], &map);
	map.normal_list = get_normal_list(&map);
	map.pos.x = 0.0f;
	map.pos.y = 0.0f;
	map.pos.z = 30.0f;
	map.pos.w = 0.0f;

	map.rot.x = 0.0f;
	map.rot.y = 0.0f;
	map.rot.z = 0.0f;
	map.rot.w = 0.0f;
	map.mlx = mlx_init();
	map.win = mlx_new_opengl_window(map.mlx, 1080, 720, "scop");	
	mlx_opengl_window_set_context(map.win);
	map.program_id = load_shaders("tri_vs.glsl", "tri_fs.glsl");
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);

	init_cam(&map);
	init_key(&map);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_hook(map.win, 2, (1L << 0), key_press, &map);
	mlx_hook(map.win, 17, (1L << 17), red_cross, &map);
	mlx_expose_hook(map.win, expose_hook, &map);	
	mlx_loop_hook(map.mlx, loop_hook, &map);
	mlx_loop(map.mlx);
}
