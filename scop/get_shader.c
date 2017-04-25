/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:13:23 by amathias          #+#    #+#             */
/*   Updated: 2016/07/23 18:39:00 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char	*get_shader_buffer(char *file_name)
{
	char	*buffer;
	char	*line;
	char	*back;
	int		fd;
	int		len;

	len = -1;
	buffer = (char*)malloc(sizeof(char) + 1);
	buffer[0] = '\0';
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		buffer = ft_strjoinfree(buffer, line);
		back = (char*)malloc(sizeof(char) + 1);
		back[0] = '\n';
		back[1] = '\0';
		buffer = ft_strjoinfree(buffer, back);
	}
	if (close(fd) == -1)
		return (NULL);
	return (buffer);
}

void	print_shader_error(GLuint shader, char *file_name)
{
	char	log[2048];
	int		max_length;
	int		index;

	max_length = 2048;
	index = 0;
	glGetShaderInfoLog(shader, max_length, &index, log);
	ft_putstr("Cannot compile shader: ");
	ft_putstr(file_name);
	ft_putstr("\n");
	ft_putstr(log);
	exit(0);
}

GLuint	get_vertex_shader(char *file_name)
{
	GLuint	vs;
	char	*buffer;
	int		error;

	error = -1;
	buffer = get_shader_buffer(file_name);
	if (!buffer)
		ft_putstr("Invalid file_name\n");
	vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, (const char**)&buffer, NULL);
	glCompileShader(vs);
	glGetShaderiv(vs, GL_COMPILE_STATUS, &error);
	if (GL_TRUE != error)
		print_shader_error(vs, file_name);
	return (vs);
}

GLuint	get_fragment_shader(char *file_name)
{
	GLuint	fs;
	char	*buffer;
	int		error;

	error = -1;
	buffer = get_shader_buffer(file_name);
	if (!buffer)
		ft_putstr("Invalid file_name\n");
	fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, (const char**)&buffer, NULL);
	glCompileShader(fs);
	glGetShaderiv(fs, GL_COMPILE_STATUS, &error);
	if (GL_TRUE != error)
		print_shader_error(fs, file_name);
	return (fs);
}

void	print_link_error(GLuint program, char *vfn, char *ffn)
{
	char	log[2048];
	int		max_length;
	int		index;

	max_length = 2048;
	index = 0;
	glGetProgramInfoLog(program, max_length, &index, log);
	glGetShaderInfoLog(program, max_length, &index, log);
	ft_putstr("Cannot link shaders: ");
	ft_putstr(vfn);
	ft_putstr(" and ");
	ft_putstr(ffn);
	ft_putstr("\n");
	ft_putstr(log);
	exit(0);
}

GLuint	load_shaders(char *vertex_file_name, char *fragment_file_name)
{
	GLuint	program;
	int		error;
	GLuint	fs;
	GLuint	vs;

	error = -1;
	fs = get_fragment_shader(fragment_file_name);
	vs = get_vertex_shader(vertex_file_name);
	program = glCreateProgram();
	glAttachShader(program, fs);
	glAttachShader(program, vs);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &error);
	if (GL_TRUE != error)
		print_link_error(program, vertex_file_name, fragment_file_name);
	return (program);
}
