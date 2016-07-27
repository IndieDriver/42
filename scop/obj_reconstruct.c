/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_reconstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 19:35:16 by amathias          #+#    #+#             */
/*   Updated: 2016/07/27 19:53:37 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		count(t_obj *obj)
{
	t_list *elem;
	t_vec4	vec;
	int i;

	elem = obj->tri;
	i = 0;
	while (elem->next)
	{
		vec = (t_vec4)elem->content;
		i = (t_vec4)elem->content.w == 0.0f ? i + 4 : i + 3;
		elem = elem->next;	
	}
	return (i);
}

float	*obj_reconstruct(t_obj *obj)
{
	(void)obj;	
}
