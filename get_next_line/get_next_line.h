/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:37:21 by amathias          #+#    #+#             */
/*   Updated: 2015/12/16 17:03:04 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 1000

typedef struct	s_buf
{
	char	buf[BUFF_SIZE + 1];
	char	*next;
	int		ret;
	int		end;
}				t_buf;

int		get_next_line(int const fd, char **line);

#endif
