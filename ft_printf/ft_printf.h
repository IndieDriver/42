/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:07:58 by amathias          #+#    #+#             */
/*   Updated: 2016/01/19 11:21:54 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

void	ft_printf(const char * restrict format, ...);

void	ft_putstr(char *str);
char	*ft_itoa_base(long n, int base);
char	*ft_strchr(const char *str, int c);
#endif
