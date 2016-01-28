/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:40:41 by amathias          #+#    #+#             */
/*   Updated: 2016/01/28 15:52:53 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_pos	get_horizontal(t_map *map, double angle)
{
	t_pos p1;
	int	xa;
	int ya;
	
	if (angle >= 0.0 && angle <= 180.0)
	{
		p1.y = (map->cpos.y / 64) * (64) - 1;
		ya = -64;
	}
	else
	{
		p1.y = (map->cpos.y / 64) * (64) + 64;
		ya = 64;
	}
	p1.x = map->cpos.x + (map->cpos.y - p1.y) / tan(angle * M_PI / 180.0);
	xa = 64 / tan(angle * M_PI / 180.0);
	//printf("horizontal\n" );
	//printf("p1.y / 64: %d, p1.x / 64: %d\n", p1.y / 64, p1.x / 64);
	while (map->grid[p1.y / 64][p1.x / 64] == 0)
	{
		//printf("p1.y / 64: %d, p1.x / 64: %d\n", p1.y / 64, p1.x / 64);
		p1.x += xa;
		p1.y += ya;
	}
	return (p1);
}

t_pos	get_vertical(t_map *map, double angle)
{
	t_pos p1;
	int xa;
	int ya;
	
	if ((angle >= 0.0 && angle <= 90.0) || (angle >= 270.0 && angle <= 360.0))
	{
		p1.x = (map->cpos.x / 64) * 64 + 64;
		xa = 64;
	}
	else
	{
		p1.x = (map->cpos.x / 64) * 64 - 1;
		xa = -64;
	}
	p1.y = map->cpos.y + (map->cpos.x - p1.x) / tan(angle * M_PI / 180.0);
	ya = 64 / tan(angle * M_PI / 180.0);
	//printf("vertical\n" );
	//printf("p1.y / 64: %d, p1.x / 64: %d\n", p1.y / 64, p1.x / 64);
	while (map->grid[p1.y / 64][p1.x / 64] == 0)
	{
		//printf("p1.y / 64: %d, p1.x / 64: %d\n", p1.y / 64, p1.x / 64);
		p1.x += xa;
		p1.y += ya;
	}
	return (p1);
}

double	get_distance(t_map *map, double angle)
{
	t_pos	hor;
	t_pos	ver;
	int		distance1;
	int		distance2;

	hor = get_horizontal(map, angle);
	ver = get_vertical(map, angle);
	//printf("hor| x: %d, y: %d\nver| x: %d, y: %d\n",hor.x,hor.y,ver.x,ver.y);
	distance1 = abs(map->cpos.x - hor.x) / cos(angle * M_PI / 180.0);
	distance2 = abs(map->cpos.x - ver.x) / cos(angle * M_PI / 180.0);
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
	double beta;
	int i;

	i = 0;	
	angle = map->cpos.r - 30;
	beta = -30.0;
	while (i < WIDTH)
	{
		printf("angle: %f\n", angle);
		distance = get_distance(map, angle) * cos(beta * M_PI / 180.0);
		printf("distance: %f\n", distance);
		height = (64 / distance) * ((WIDTH / 2) / tan(30.0 * M_PI / 180.0));
		draw_wall_slice(map, i, height);
		angle += (60.0 / WIDTH);
		beta += (60.0 / WIDTH);
		i++;
	}
}
