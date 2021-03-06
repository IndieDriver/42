/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:00:55 by amathias          #+#    #+#             */
/*   Updated: 2015/12/03 13:58:35 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (!((c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')))
		return (0);
	return (1);
}
