/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 13:07:58 by amathias          #+#    #+#             */
/*   Updated: 2016/01/18 17:07:08 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
#include <stdio.h>

typedef struct		s_type
{
	int				d;
	unsigned int 	u;
	double			f;
	char			c;
}					t_type;
void	ft_printf(const char * restrict format, ...);

char	*ft_itoa_base(long n, int base);
#endif
