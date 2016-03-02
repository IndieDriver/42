/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:03:58 by amathias          #+#    #+#             */
/*   Updated: 2016/03/02 13:33:13 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	*shape_cmp(void *shape1, void *shape2)
{
	t_sphere *t1;
	t_sphere *t2;

	if (!shape1 && !shape2)
		return (NULL);
	if (shape1 && !shape2)
		return (shape1);
	if (!shape1 && shape2)
		return (shape2);
	t1 = shape1;
	t2 = shape2;
	if (t1->t < t2->t)
		return (shape1);
	else if (t1->t > t2->t)
		return (shape2);
	else
		return (shape2);
}

void	*get_nearest(t_sphere *sph, t_plan *plan, t_cylinder *cyl, t_cone *cone)
{
	void *shape;

	shape = shape_cmp(sph, plan);
	shape = shape_cmp(shape, cyl);
	shape = shape_cmp(shape, cone);
	return (shape);
}	
