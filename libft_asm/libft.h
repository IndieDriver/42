/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:04:52 by amathias          #+#    #+#             */
/*   Updated: 2015/12/12 11:01:02 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>


typedef struct		s_vec4
{
	union {
		float s[4];
		struct {
			float	x;
			float	y;
			float	z;
			float	w;
		};
	};
}				t_vec4;



int					ft_puts(char const *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
char				*ft_strcat(char *dest, const char *src);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				ft_cat(int fd);

float				ft_vec4len(t_vec4 vec);
void				ft_vec4normalize(t_vec4 *vec);
t_vec4				ft_vec4scale(t_vec4	vec, float scale);
float				ft_vec4dot(t_vec4 vec1, t_vec4 vec2);
float				ft_vec4distance(t_vec4 vec1, t_vec4 vec2);


#endif
