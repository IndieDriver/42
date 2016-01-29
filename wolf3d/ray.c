/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 11:40:41 by amathias          #+#    #+#             */
/*   Updated: 2016/01/29 15:16:20 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		is_inside_grid(t_map *map, int x, int y)
{
	if ((y / 64 >= 0 && y / 64 > map->height)
			&& (x / 64 >= 0 && x / 64 > map->height))
		return (1);
	return (0);
}

t_pos	get_horizontal(t_map *map, double angle)
{
	t_pos p1;
	int	xa;
	int ya;

	if (angle >= 0.0 && angle < 180.0)
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
	while (is_inside_grid(map, p1.x, p1.y))
	{
		if (is_inside_grid(map, p1.x - 32, p1.y - 32)
				&& map->grid[(p1.y - 32) / 64][(p1.x - 32) / 64] == 0)
			break ;
		if (is_inside_grid(map, p1.x + 32, p1.y + 32)
				&& map->grid[(p1.y + 32) / 64][(p1.x + 32) / 64] == 0)
			break ;
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

	if ((angle >= 0.0 && angle < 90.0) || (angle >= 270.0 && angle <= 360.0))
	{
		p1.x = (map->cpos.x / 64) * (64) + 64;
		xa = 64;
	}
	else
	{
		p1.x = (map->cpos.x / 64) * (64) - 1;
		xa = -64;
	}
	p1.y = map->cpos.y + (map->cpos.x - p1.x) / tan(angle * M_PI / 180.0);
	ya = 64 / tan(angle * M_PI / 180.0);	
	while (is_inside_grid(map, p1.x, p1.y))
	{
		if (is_inside_grid(map, p1.x - 32, p1.y - 32)
				&& map->grid[(p1.y - 32) / 64][(p1.x - 32) / 64] == 0)
			break ;
		if (is_inside_grid(map, p1.x + 32, p1.y + 32)
				&& map->grid[(p1.y + 32) / 64][(p1.x + 32) / 64] == 0)
			break ;
		p1.x += xa;
		p1.y += ya;
	}
	return (p1);
}

double	get_distance(t_map *map, double angle)
{
	t_pos	hor;
	t_pos	ver;
	double	distance1;
	double	distance2;

	hor = get_horizontal(map, angle);
	ver = get_vertical(map, angle);
	printf("hor| x: %d, y: %d\nver| x: %d, y: %d\n",hor.x,hor.y,ver.x,ver.y);
	distance1 = abs(hor.y - map->cpos.y) / sin(angle * M_PI / 180.0);
	distance2 = abs(ver.y - map->cpos.y) / sin(angle * M_PI / 180.0);
	printf("distance1: %f| distance2: %f\n", distance1, distance2);
	if (distance1 < distance2 && distance1 != 0.0)
		return (distance1);
	else
		return (distance2);

}
void	ray(t_map *map)
{
	double distance;
	int height;
	double angle;
	double beta;
	int i;

	i = 0;
	angle = map->cpos.r - 30;
	beta = -30.0;
	while (i < WIDTH)
	{
		printf("angle: %f beta: %f\n", angle, beta);
		distance = get_distance(map, angle) * cos(beta * M_PI / 180.0);
		printf("distance: %f\n", distance);
		height = (64 / distance) * 255;
		printf("height: %d\n",height);
		draw_wall_slice(map, i, height / 2);
		printf("draw_wall_slice()\n");
		angle += (60.0 / WIDTH);
		beta += (60.0 / WIDTH);
		i++;
	}
}
