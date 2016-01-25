/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:28:49 by amathias          #+#    #+#             */
/*   Updated: 2016/01/25 15:22:40 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLD3D_H
# define WOLD3D_H
# include <mlx.h>
# include <math.h>
#include <stdio.h>
# include "libft.h"
# define WIDTH 640
# define HEIGHT 420
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

typedef struct 	s_pos
{
	double		x;
	double 		y;
	int			r;
}				t_pos;

typedef struct	s_map
{
	t_env		env;
	t_img		img;
	int			type;
	int			**grid;
	int			height;
	int			width;
	t_pos		cpos;

}				t_map;

void			draw(t_map *map);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

int				expose_hook(t_map *map);
int				motion_notify(int x, int y, t_map *map);
int				key_hook(int keycode, t_map *map);

#endif
