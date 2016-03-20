/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 12:53:27 by amathias          #+#    #+#             */
/*   Updated: 2016/03/20 13:15:03 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_args(t_args *arg1, t_args *arg2, t_args *arg3, t_args *arg4)
{
	free(arg1);
	free(arg2);
	free(arg3);
	free(arg4);
}

t_args	*init_thread(t_map *map, t_pos min, t_pos max)
{
	t_args *arg;

	arg = malloc(sizeof(t_args));
	arg->m = map;
	arg->min = min;
	arg->max = max;
	return (arg);
}

void	multi_thread(t_map *map, void *function)
{
	pthread_t	tid[4];
	t_args		*a1;
	t_args		*a2;
	t_args		*a3;
	t_args		*a4;

	a1 = init_thread(map, get_pos(0, 0), get_pos(WIDTH / 4, 0));
	a2 = init_thread(map, get_pos(WIDTH / 4, 0), get_pos(WIDTH / 4 * 2, 0));
	a3 = init_thread(map, get_pos(WIDTH / 4 * 2, 0), get_pos(WIDTH / 4 * 3, 0));
	a4 = init_thread(map, get_pos(WIDTH / 4 * 3, 0), get_pos(WIDTH, 0));
	pthread_create(&tid[0], NULL, function, (void*)a1);
	pthread_create(&tid[1], NULL, function, (void*)a2);
	pthread_create(&tid[2], NULL, function, (void*)a3);
	pthread_create(&tid[3], NULL, function, (void*)a4);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	free_args(a1, a2, a3, a4);
}
