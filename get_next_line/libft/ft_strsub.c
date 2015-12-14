/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:22:25 by amathias          #+#    #+#             */
/*   Updated: 2015/12/08 17:36:20 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *str;

	if (s)
	{
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		if (str)
		{
			while (start--)
				s++;
			ft_strncpy(str, s, len);
			str[len] = '\0';
		}
		return (str);
	}
	return (NULL);
}
