/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:49:42 by amathias          #+#    #+#             */
/*   Updated: 2016/02/18 16:10:23 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int type)
{
	if (type == 1)
		ft_putstr("malloc error");
	if (type == 2)
		ft_putstr("Invalid arg\n./fractol <julia|mandelbrot|burning>\n");
	exit(0);
}
