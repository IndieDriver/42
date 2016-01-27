/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:40:41 by amathias          #+#    #+#             */
/*   Updated: 2016/01/27 15:52:28 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pos	get_horizontal(t_map *map, double angle)
{
	t_pos p1;
	t_pos p2;
	int xa;
	int ya;

	if (angle > 180 && angle < 360)
	{
		p1.y = floor(map->cpos.y / 64) * 64 - 1;
		ya = -64;
	}
	else if (angle > 0 && angle < 180)
	{
		p1.y = floor(map->cpos.y / 64) * 64 + 64;
		ya = 64;
	}
	p1.x = map->cpos.x + (map->cpos.y - p1.y) / tan(angle);
	xa = 64 / tan(60);
	p2 = p1;
	printf("while\n");
	printf("p2.y / 64: %d p2.x / 64: %d\n",p2.y/64, p2.x / 64);
	while (p2.y / 64 < map->height && p2.x / 64 < map->width
			&& map->grid[p2.y / 64][p2.x / 64] == 0)
	{
		printf("p2.y / 64: %d p2.x / 64: %d\n",p2.y/64, p2.x / 64);
		p2.y = p2.y + ya;
		p2.x = p2.x + xa;
	}
	return (p2);
}

t_pos	get_vertical(t_map *map, double angle)
{
	t_pos p1;
	t_pos p2;
	int xa;
	int ya;

	if ((angle > 270 && angle < 360) || (angle > 0 && angle < 90))
	{
		p1.x = (floor(map->cpos.x / 64) * 64) - 1;
		xa = 64;
	}
	else if (angle > 90 && angle < 270)
	{
		p1.x = (floor(map->cpos.x / 64) * 64) + 64;
		xa = -64;
	}
	p1.y = map->cpos.y + (map->cpos.x - p1.x) / tan(angle);
	ya = 64 / tan(60);
	p2 = p1;
	printf("while\n");
	printf("p2.y / 64: %d p2.x / 64: %d\n",p2.y/64, p2.x / 64);
	while (p2.y / 64 < map->height &&
			p2.x / 64 < map->width && map->grid[p2.y / 64][p2.x / 64] == 0)
	{
		printf("p2.y / 64: %d p2.x / 64: %d\n",p2.y/64, p2.x / 64);
		p2.y = p2.y + ya;
		p2.x = p2.x + xa;
	}
	return (p2);
}

double	get_distance(t_map *map, double angle)
{
	t_pos	hor;
	t_pos	ver;
	int		distance1;
	int		distance2;

	hor = get_horizontal(map, angle);
	ver = get_vertical(map, angle);
	printf("hor| x: %d, y: %d\nver| x: %d, y: %d\n",hor.x,hor.y,ver.x,ver.y);
	distance1 = abs(map->cpos.x - hor.x) / cos(60.0);
	distance2 = abs(map->cpos.x - ver.x) / cos(60.0);
	if (distance1 < distance2)
		return (distance1);
	else
		return (distance2);

}
void	ray(t_map *map)
{
	double distance;
	double height;
	double angle;
	int i;

	i = 0;	
	angle = map->cpos.r - 30;
	while (i < WIDTH)
	{
		printf("angle: %f\n", angle);
		distance = get_distance(map, angle);
		height = (64 / distance) * ((WIDTH / 2) / tan(30.0));
		draw_wall_slice(map, i, height);
		angle += (60.0 / WIDTH);
		i++;
	}
}
