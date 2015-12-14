/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:21:33 by amathias          #+#    #+#             */
/*   Updated: 2015/12/08 17:17:00 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (s && f)
	{
		str = ft_strdup((const char *)s);
		if (str == NULL)
			return (NULL);
		i = 0;
		while (s + i != NULL && str[i] != 0)
		{
			str[i] = f((unsigned int)i, str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
