/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 15:24:11 by amathias          #+#    #+#             */
/*   Updated: 2016/01/06 17:24:08 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "libft.h"
# define HEIGHT 680
# define WIDTH	480

typedef struct	s_env
{
	void		*mlx;
	void		*win;
}				t_env;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

t_point			convertcord(int x, int y);
void			draw_iso(t_env env, int grid[4][4], int row, int col);
#endif
