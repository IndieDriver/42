/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:49:42 by amathias          #+#    #+#             */
/*   Updated: 2016/02/19 15:15:30 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int type)
{
	if (type == 1)
		ft_putstr("malloc error");
	if (type == 2)
		ft_putstr("Invalid arg\n./fractol <julia|mandelbrot|burning>\n");
	exit(0);
}

int		get_color(int iter)
{
	return (256 * 256 * (256 - sin(iter) * 10) +
			256 + (256 - cos(iter)) + (256 - cos(iter)));
}

void	free_args(t_args *arg1, t_args *arg2, t_args *arg3, t_args *arg4)
{
	free(arg1);
	free(arg2);
	free(arg3);
	free(arg4);
}

t_args	*init_thread(t_map *map, t_point min, t_point max)
{
	t_args *arg;
	
	arg = malloc(sizeof(t_args));
	arg->map = map;
	arg->min = min;
	arg->max = max;
	return (arg);
}

void	multi_thread(t_map *map, void *function)
{
	pthread_t	tid[4];
	t_args		*arg1;
	t_args		*arg2;
	t_args		*arg3;
	t_args		*arg4;

	arg1 = init_thread(map, setpoint(0, 0, 0, 0),
					setpoint(WIDTH / 2, HEIGHT / 2, 0, 0));
	arg2 = init_thread(map, setpoint(WIDTH / 2, 0, 0, 0),
					setpoint(WIDTH, HEIGHT / 2, 0, 0));
	arg3 = init_thread(map, setpoint(0, HEIGHT / 2, 0, 0),
					setpoint(WIDTH / 2, HEIGHT, 0, 0));
	arg4 = init_thread(map, setpoint(WIDTH / 2, HEIGHT / 2, 0, 0),
					setpoint(WIDTH, HEIGHT, 0, 0));
	pthread_create(&tid[0], NULL, function, (void*)arg1);
	pthread_create(&tid[1], NULL, function, (void*)arg2);
	pthread_create(&tid[2], NULL, function, (void*)arg3);
	pthread_create(&tid[3], NULL, function, (void*)arg4);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	free_args(arg1, arg2, arg3, arg4);
}
