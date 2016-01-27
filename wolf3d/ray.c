/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:40:41 by amathias          #+#    #+#             */
/*   Updated: 2016/01/27 10:42:15 by amathias         ###   ########.fr       */
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

double	get_distance(t_map *map, double angle)
{
	t_pos	hor;
	t_pos	ver;
	double	distance1;
	double	distance2;

	hor = get_horizontal(map, angle).x;
	ver = get_vertical(map, angle).y;
	distance1 = fabs(map->cpos.x - hor.x) / cos(60);
	distance2 = fabs(map->cpos.x - ver.x) / cos(60);
	if (distance1 < distance2)
		return (distance1);
	else
		return (distance2);

}
void	ray(t_map *map)
{
	t_pos wallpos;
	t_pos distance;
	double angle;
	int i;
	
	angle = map->cpos.r - 30;
	while (i < map->width)
	{
		wallpos.x = get_horizontal(map, angle).x;
		wallpos.y = get_vertial(map, angle).y;
		distance.x = ()
		i++;
	}r

}
