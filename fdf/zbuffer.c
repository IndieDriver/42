/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:46:57 by amathias          #+#    #+#             */
/*   Updated: 2016/01/11 16:17:25 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_rect(t_env env, t_rect rect)
{
	printf("fill_rect\n");
	t_point *plist;

	rect.tl.x++;
	rect.tl.y++;

	rect.tr.x--;
	rect.tr.y++;

	rect.bl.x++;
	rect.bl.y--;

	rect.br.x--;
	rect.br.y--;
	while (rect.tl.x != rect.tr.x)
	{
		draw_line(env, rect.tl, rect.bl);
		rect.tl.x++;
	}
}
