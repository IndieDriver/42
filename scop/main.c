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

t_vec3	get_offset(t_map *map)
{
	t_vec3	offset;
	int		i;

	i = 0;
	offset = get_vec3(0.0f, 0.0f, 0.0f);
	while (i < map->nb_vertex)
	{
		offset.x += map->vertex_array[i].x;
		offset.y += map->vertex_array[i].y;
		offset.z += map->vertex_array[i].z;
		i++;
	}
	offset.x = offset.x / (map->nb_vertex);
	offset.y = offset.y / (map->nb_vertex);
	offset.z = offset.z / (map->nb_vertex);
	return (offset);
}

void	init_key(t_map *map)
{
	map->key.up = 0;
	map->key.down = 0;
	map->key.left = 0;
	map->key.right = 0;
	map->key.rup = 0;
	map->key.rdown = 0;
	map->key.kspace = 0;
}

void	init_texture(t_map *map)
{
	t_bmp	bmp;

	bmp = parse_bmp("texture.bmp");
	map->has_texture = 0;
	glGenTextures(1, &map->texture_id);
	glBindTexture(GL_TEXTURE_2D, map->texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp.width, bmp.height, 0, GL_BGR,
		GL_UNSIGNED_BYTE, bmp.data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	free(bmp.data);
}

void	init_cam(t_map *map)
{
	apply_trans(map->modelmat4, map->pos, map->rot);
	get_viewmatrix(map, get_vec4(5.0f, 0.0f, 0.0f, 0.0f),
						get_vec4(0.0f, 0.0f, 0.0f, 0.0f),
						get_vec4(0.0f, 1.0f, 0.0f, 0.0f));
	get_projmatrix(map->projmat4, 45.0f, 1080.0f / 720.0f);
	get_mvp(map->mvpmat4, map->modelmat4, map->viewmat4, map->projmat4);
	get_normalmat(map->normalmat4, map->modelmat4, map->viewmat4);
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		exit(0);
	parse_obj_file(argv[1], &map);
	set_normal_array(&map);
	set_uv_array(&map);
	map.pos = neg_vec4(vec3tovec4(get_offset(&map)));
	map.init_pos = map.pos;
	map.mlx = mlx_init();
	map.win = mlx_new_opengl_window(map.mlx, 1080, 720, "scop");
	mlx_opengl_window_set_context(map.win);
	map.program_id = load_shaders("tri_vs.glsl", "tri_fs.glsl");
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
	init_texture(&map);
	init_cam(&map);
	init_key(&map);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_hook(map.win, 2, (1L << 0), key_press, &map);
	mlx_hook(map.win, 17, (1L << 17), red_cross, &map);
	mlx_expose_hook(map.win, expose_hook, &map);
	mlx_loop_hook(map.mlx, loop_hook, &map);
	mlx_loop(map.mlx);
}
