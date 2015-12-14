/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrimino.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:16:05 by amathias          #+#    #+#             */
/*   Updated: 2015/12/14 13:56:44 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_setpos(t_tetri *list, int index)
{
	int i;

	i = 0;
	while (list[index].tab[0].x != 0 || list[index].tab[0].y != 0)
	{
		while (list[index].tab[0].x > 0)
		{
			i = 0;
			while (i < 4)
			{
				list[index].tab[i].x--;
				i++;
			}
		}
		while (list[index].tab[0].y > 0)
		{
			i = 0;
			while (i < 4)
			{
				list[index].tab[i].y--;
				i++;
			}
		}
	}
}

int			ft_addtetri(t_tetri *list, char *str)
{
	int i;
	int cursor;
	int bloc;

	i = 0;
	cursor = 0;
	bloc = 0;
	while (list[cursor].tab[0].x != -1 && cursor != 26)
		cursor++;
	if (cursor == 26)
		return (0);
	while (str[i])
	{
		if (str[i] == '#')
		{
			list[cursor].tab[bloc].x = i % 5;
			list[cursor].tab[bloc].y = i / 5;
			list[cursor].index = cursor;
			bloc++;
		}
		i++;
	}
	ft_setpos(list, cursor);
	return (1);
}

t_tetri		*ft_inittetriminos(void)
{
	t_tetri *tmp;
	int		i;

	i = 0;
	if ((tmp = malloc(sizeof(t_tetri) * 27)) == NULL)
		return (NULL);
	while (i < 26)
	{
		tmp[i].tab[0].x = -1;
		i++;
	}
	return (tmp);
}

static int	ft_checkcontact(char *str, int index)
{
	int	contact;

	contact = 0;
	if (str[index] == '#')
	{
		contact++;
		str[index] = 'X';
		if (index % 5 != 0)
			contact += ft_checkcontact(str, index - 1);
		if (index % 3 != 3)
			contact += ft_checkcontact(str, index + 1);
		if (index > 4)
			contact += ft_checkcontact(str, index - 5);
		if (index < 15)
			contact += ft_checkcontact(str, index + 5);
	}
	return (contact);
}

int		ft_isvalid(const char *str)
{
	int		bloc;
	int		i;
	char	*tmp;

	i = -1;
	bloc = 0;
	while (str[++i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i] == '\n' && (i % 5 != 4 && i != 20))
			return (0);
		if (str[i] == '#')
			bloc++;
	}
	if ((i = -1) && bloc != 4 && (i - 1 != 20 || i - 1 != 19))
		return (0);
	tmp = ft_strdup(str);
	while (tmp[++i])
	{
		if (tmp[i] == '#' && (ft_checkcontact(tmp, i)) != 4)
			return (0);
	}
	free(tmp);
	return (1);
}
