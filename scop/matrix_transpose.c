/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 10:10:07 by amathias          #+#    #+#             */
/*   Updated: 2016/08/22 10:23:03 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	transpose(t_mat4 out)
{
	float	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			tmp = out[i * 4 + j];
			out[i * 4 + j] = out[j * 4 + i];
			out[j * 4 + i] = tmp;
			j++;
		}
		i++;
	}
}
