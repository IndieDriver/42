/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:40:41 by amathias          #+#    #+#             */
/*   Updated: 2016/01/25 15:55:46 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_pos	get_horizontal(t_map *map, int angle)
{
	t_pos p1;
	t_pos p2;
	int xa;
	int ya;

	if (angle > 180 && angle < 360)
	{
		p1.y = (floor(map->cpos.y / 64) * 64);
		ya = -64;
	}
	else if (angle > 0 && angle < 180)
	{
		p1.y = (floor(map->cpos.y / 64) * 64) + 64;
		ya = 64;
	}
	p1.x = map->cpos.x + (map->cpos.y - p1.y) / tan(60);
	xa = 64 / tan(60);
	p2 = p1;
	while (grid[p2.y / 64][p2.y / 64] == 0)
	{
		p2.y = p2.y + ya;
		p2.x = p2.x + xa;
	}
	return (p2);
}

t_pos	get_vertical(t_map *map, int angle)
{
	t_pos p1;
	t_pos p2;
	int xa;
	int ya;

	if ((angle > 270 && angle < 360) || (angle > 0 && angle < 90))
	{
		p1.x = (floor(map->cpos.y / 64) * 64);
		xa = 64;
	}
	else if (angle > 90 && angle < 270)
	{
		p1.x = (floor(map->cpos.y / 64) * 64) + 64;
		xa = -64;
	}
	p1.y = map->cpos.y + (map->cpos.x - p1.x) / tan(60);
	ya = 64 / tan(60);
	p2 = p1;
	while (grid[p2.y / 64][p2.y / 64] == 0)
	{
		p2.y = p2.y + ya;
		p2.x = p2.x + xa;
	}
	return (p2);
}


void	ray(t_map *map)
{
	int angle;
	int i;
	
	angle = map->cpos.r - 30;
	while (i < map->width)
	{
		
		i++;
	}

}
