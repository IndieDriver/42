/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:24:11 by amathias          #+#    #+#             */
/*   Updated: 2016/02/11 16:26:36 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "libft.h"
# include "../fractol.h"

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_line;

t_point			setpoint(int x, int y, int z, int color);
t_point			convertcord(t_point point);
void			draw_iso(t_map *map, t_point **grid, int row, int col);
t_map			*adapt_grid(t_map *map);

void			draw_line(t_map *map, t_point from, t_point to, int color);

void			draw(t_map *map);
void			shift_grid(t_map *map);
void			ft_error(void);

int				get_color(int i);
int				get_hex_color(t_map *map, int x, int y);
void			draw_pixel_to_image(t_map *map, int x, int y, int color);
void			init_image(t_map *map, int color);

t_point			**copy_grid(t_map *map, t_point **src);

void			get_move(t_map *map);
void			move(t_map *map, int sx, int sy);
void			zoom(t_map *map, int zoom);

void			init_key(t_map *map);
int				loop_hook(t_map *map);
int				expose_hook(t_map *map);
int				key_hook(int keycode, t_map *map);
int				key_press(int keycode, t_map *map);
#endif

*/
