/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:33:36 by amathias          #+#    #+#             */
/*   Updated: 2015/12/08 18:38:00 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	tmp1 = (unsigned char*)str1;
	tmp2 = (unsigned char*)str2;
	while (tmp1[i] == tmp2[i] && tmp1[i] != '\0' && tmp2[i] != '\0')
		i++;
	return (tmp1[i] - tmp2[i]);
}
