/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 12:59:32 by amathias          #+#    #+#             */
/*   Updated: 2016/01/22 14:30:30 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <math.h>
#include <stdio.h>
# include "libft.h"
# define WIDTH 1000
# define HEIGHT 1000
# include "libft.h"

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

typedef struct	s_map
{
	t_env		env;
	t_img		img;
	double		zoom;
	int			pow;
}				t_map;

typedef struct	s_complex
{
	double		real;
	double		ima;
}				t_complex;

void			draw(t_map *map);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

void			draw_julia(t_map *map, int max_iter, double zoom);
void			draw_mandelbrot(t_map *map, int max_iter);
#endif
