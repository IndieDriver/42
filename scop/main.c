/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 13:31:16 by amathias          #+#    #+#             */
/*   Updated: 2016/07/27 19:02:42 by amathias         ###   ########.fr       */
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
}
int		main(int argc, char **argv)
{
	t_map map;

	(void)argc;
	(void)argv;
	//if (argc != 2)
	//	exit(0);
	//parse_obj_file(argv[1]);
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

	init_cam(&map);
	init_key(&map);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_hook(map.win, 2, (1L << 0), key_press, &map);
	mlx_hook(map.win, 17, (1L << 17), red_cross, &map);
	mlx_expose_hook(map.win, expose_hook, &map);	
	mlx_loop_hook(map.mlx, loop_hook, &map);
	mlx_loop(map.mlx);
}
