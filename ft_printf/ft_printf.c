/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:05:01 by amathias          #+#    #+#             */
/*   Updated: 2016/01/14 15:46:12 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void  lol(void *c)
{
	printf("%c", (char)c);
}

void	*get_function()
{
	return (&lol);
}

void	ft_printf(const char * restrict format, ...)
{
	int i;
	va_list args;
	void	(*f)(void *);

	i = 0;	
	va_start(args, format);
	f = get_function();
	while (format[i] != '\0')
	{
		(*f)format[i]);
		i++;
	}
	
}
