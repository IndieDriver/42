/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:14:09 by amathias          #+#    #+#             */
/*   Updated: 2015/11/26 17:02:30 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	while (count >= 0)
	{
		if (str[count] == (char)c)
			return ((char*)&str[count]);
		count--;
	}
	return (NULL);
}
