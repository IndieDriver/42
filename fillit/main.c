/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:15:43 by amathias          #+#    #+#             */
/*   Updated: 2015/12/14 15:02:13 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_getnumberoftetri(t_tetri *list)
{
	int i;

	i = 0;
	while (list[i].tab[0].x != -1)
		i++;
	return (i);
}

static int		ft_readfile(t_tetri *list, char *filename)
{
	int		fd;
	int		ret;
	char	buf[22];

	list = ft_inittetriminos();
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (!ft_isvalid(buf))
			return (0);
		if (!ft_addtetri(list, buf))
			return (0);
	}
	if (ft_getnumberoftetri(list) == 0)
		return (0);
	ft_solve(list);
	if (close(fd) == -1)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_tetri *list;

	list = NULL;
	if (argc == 2)
	{
		if (!ft_readfile(list, argv[1]))
			ft_putstr("error\n");
		free(list);
	}
	else
		ft_putstr("error\n");
}
