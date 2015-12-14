/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:19:51 by amathias          #+#    #+#             */
/*   Updated: 2015/12/03 16:20:42 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (!del || !alst)
		return ;
	tmp = *alst;
	while (tmp)
	{
		next = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
