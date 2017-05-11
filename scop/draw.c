/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 14:47:58 by amathias          #+#    #+#             */
/*   Updated: 2016/09/15 12:33:50 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	draw(t_map *map)
{
	GLuint	point_vbo = 0;
	GLuint	normal_vbo = 0;
	GLuint	uv_vbo = 0;
	GLuint	indice_vbo = 0;
	GLuint	vao = 0;

	glGenBuffers(1, &point_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, point_vbo);
	glBufferData(GL_ARRAY_BUFFER, (map->nb_vertex * 3) * sizeof(float),
		map->vertex_array, GL_STATIC_DRAW);

	glGenBuffers(1, &normal_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, normal_vbo);
	glBufferData(GL_ARRAY_BUFFER, (map->nb_vertex * 3) * sizeof(float),
		map->normal_list, GL_STATIC_DRAW);

	glGenBuffers(1, &uv_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, uv_vbo);
	glBufferData(GL_ARRAY_BUFFER, (map->nb_vertex * 2) * sizeof(float),
		map->uv_list, GL_STATIC_DRAW);

	glGenBuffers(1, &indice_vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indice_vbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (map->nb_indice) * sizeof(unsigned int),
			map->indice_array, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, point_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, normal_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, uv_vbo);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indice_vbo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	map->mvpmat4_id = glGetUniformLocation(map->program_id, "MVP");
	map->normalmat4_id = glGetUniformLocation(map->program_id, "MV");

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glUseProgram(map->program_id);

	glUniformMatrix4fv(map->mvpmat4_id, 1, GL_FALSE, map->mvpmat4);
	glUniformMatrix4fv(map->normalmat4_id, 1, GL_FALSE, map->normalmat4);

	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, map->nb_indice, GL_UNSIGNED_INT, NULL);
	mlx_opengl_swap_buffers(map->win);
}
