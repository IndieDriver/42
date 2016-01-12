/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zbuffer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:46:57 by amathias          #+#    #+#             */
/*   Updated: 2016/01/12 16:43:03 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rect	init_rect()
{
	t_rect tmp;
	
	tmp.tl.x = 0;
	tmp.tl.y = 0;
	tmp.tr.x = 0;
	tmp.tr.y = 0;
	tmp.bl.x = 0;
	tmp.bl.y = 0;
	tmp.br.x = 0;
	tmp.br.y = 0;
	return (tmp);	
}

t_rect	*init_rectlist(t_map *map)
{
	t_rect *grid;
	int i;

	i = 0;
	if (!(grid = (t_rect*)malloc(sizeof(t_rect) * (map->width * map->height))))
		return (NULL);
	while (i < map->width * map->height)
	{
		grid[i] = init_rect();
		i++;	
	}
	printf("end init\n");
	return (grid);
}

void	save_rect(t_map *map, t_rect rect)
{
	int cursor;

	cursor = 0;
	while (map->rect[cursor].tl.x != 0 && map->rect[cursor].tr.x != 0)
		cursor++;
	map->rect[cursor] = rect;
	printf("cursor: %d\n",cursor);
}
