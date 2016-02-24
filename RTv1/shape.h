/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:48:23 by amathias          #+#    #+#             */
/*   Updated: 2016/02/24 17:47:38 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H
# include "rtv1.h"

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
	double		dir;
}				t_vec;

typedef struct	s_plan
{
	t_vec		pos;
	int			color;
}				t_plan;

typedef struct	s_sphere
{
	t_vec		pos;
	double		radius;
	int			color;
}				t_sphere;

typedef struct	s_cylinder
{
	t_vec		pos;
	double		radius;
	int			color;
}				t_cylinder;

typedef struct	s_cone
{
	t_vec		pos;
	double		base_radius;
	int			color;
}				t_cone;

typedef struct	s_scene
{
	t_vec		pos;
	int			w;
	int			h;
	t_sphere	*sphere;
	t_plan		*plan;
	t_cylinder	*cylinder;
	t_cone		*cone;
}				t_scene;
#endif
