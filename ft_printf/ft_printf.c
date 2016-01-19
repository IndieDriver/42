/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:05:01 by amathias          #+#    #+#             */
/*   Updated: 2016/01/19 12:52:08 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_type(char type, va_list args)
{
	if (type == 'd' || type == 'i')
		ft_putstr(ft_itoa_base(va_arg(args, long),10));
	if (type == 'x')
		ft_putstr(ft_itoa_base(va_arg(args, long), 16));
	if (type == 'X')
		ft_putstr(ft_itoa_base(va_arg(args, long), 16));
	if (type == 'o')
		ft_putstr(ft_itoa_base(va_arg(args, long), 8));
	return (0);
}
void	ft_printf(const char * restrict format, ...)
{
	int i;
	int perc;
	va_list args;

	i = 0;
	perc = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (perc && ft_strchr("sSpdDioOuUxXcC",format[i]) != NULL)
		{
			perc = 0;
			print_type(format[i], args);
		}
		else if (format[i] == '%')
			perc = 1;
		else
			ft_putstr((char*)&format[i]);
		i++;
	}
	va_end(args);
	
}
