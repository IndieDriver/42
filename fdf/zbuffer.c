/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:46:57 by amathias          #+#    #+#             */
/*   Updated: 2016/01/11 16:40:20 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_rect(t_env env, t_rect rect)
{
	printf("fill_rect\n");

	while (rect.tl.x != rect.tr.x && rect.tl.y != rect.tr.y)
	{
		rect.tl.x++;
		rect.tl.y++;
		rect.tr.x--;
		rect.tr.y++;
		rect.bl.x++;
		rect.bl.y--;
		rect.br.x--;
		rect.br.y--;

		draw_line(env, rect.tl, rect.tr);
		draw_line(env, rect.tr, rect.br);
		draw_line(env, rect.br, rect.bl);
		draw_line(env, rect.bl, rect.tl);
	}
}
