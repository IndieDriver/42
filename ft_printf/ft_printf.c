/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:05:01 by amathias          #+#    #+#             */
/*   Updated: 2016/01/18 16:38:15 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(char type, void *arg)
{

}
void	ft_printf(const char * restrict format, ...)
{
	int i;
	int perc;
	t_type type;
	va_list args;

	i = 0;
	perc = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (perc && ft_strchr("sSpdDioOuUxXcC",format[i]) != NULL)
			to_rename(format[i], va_arg());
		format[i];
		i++;
	}
	
}
