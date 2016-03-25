/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 13:48:23 by amathias          #+#    #+#             */
/*   Updated: 2016/03/25 14:09:13 by amathias         ###   ########.fr       */
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
}				t_vec;

typedef struct	s_plan
{
	double		t;
	int			color;
	int			type;
	t_vec		pos;
	t_vec		normal;
}				t_plan;

typedef struct	s_sphere
{
	double		t;
	int			color;
	int			type;
	t_vec		pos;
	t_vec		normal;
	double		radius;
}				t_sphere;

typedef struct	s_cylinder
{
	double		t;
	int			color;
	int			type;
	t_vec		pos;
	t_vec		normal;
	double		radius;
	t_vec		axis;
}				t_cylinder;

typedef struct	s_cone
{
	double		t;
	int			color;
	int			type;
	t_vec		pos;
	t_vec		normal;
	double		k;
	t_vec		axis;
}				t_cone;

typedef struct	s_scene
{
	t_vec		pos;
	int			w;
	int			h;
	int			nb_sph;
	int			nb_plan;
	int			nb_cone;
	int			nb_cyl;
	int			nb_spot;
	t_vec		*light;
	t_vec		*spot;
	t_sphere	*sphere;
	t_plan		*plan;
	t_cylinder	*cylinder;
	t_cone		*cone;
}				t_scene;
#endif
