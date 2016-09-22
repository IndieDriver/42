/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 17:55:00 by amathias          #+#    #+#             */
/*   Updated: 2016/09/22 16:39:37 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PART_HPP
# define PART_HPP
# include "mlx.h"
# include "mlx_opengl.h"
# include <OpenGl/gl3.h>
# include <math.h>

class				Env
{
	public:
		void			*mlx;
		void			*win;
		Env();
};

Env::Env()
{
	char name[] = "Particle System";
	this->mlx = mlx_init();
	this->win = mlx_new_opengl_window(this->mlx, 1080, 720, name);
	mlx_opengl_window_set_context(this->win);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);
};

#endif
