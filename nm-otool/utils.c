/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathias <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 14:47:44 by amathias          #+#    #+#             */
/*   Updated: 2017/04/03 08:56:51 by amathias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nmotool.h"

uint32_t	swap_byte32_t(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | (val >> 16);
}

int			ft_contain_symbol(t_symbol **head, char *name)
{
	t_symbol *symbol;

	symbol = *head;
	if (symbol == NULL || name == NULL)
		return (0);
	while (symbol)
	{
		if (symbol->sym_name != NULL && ft_strcmp((char*)symbol->sym_name, name) == 0)
			return (1);
		symbol = symbol->next;
	}
	return (0);
}

t_symbol	*ft_new_symbol(void *name, void *symbolptr)
{
	t_symbol *symbol;

	symbol = NULL;
	if ((symbol = malloc(sizeof(t_symbol))) == NULL)
		return (NULL);
	symbol->sym_name = name;
	symbol->symbol = symbolptr;
	symbol->next = NULL;
	return (symbol);
}

void	ft_lst_sorted_insert_addr(t_symbol **head, t_symbol *new,
		void *string_table_ptr)
{
	t_symbol *symbol;

	if (*head == NULL || ((*head)->sym_name - string_table_ptr)
			>= (new->sym_name - string_table_ptr))
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		symbol = *head;
		while (symbol->next
			&& (symbol->next->sym_name - string_table_ptr) <
				(new->sym_name - string_table_ptr))
		{
			symbol = symbol->next;
		}
		new->next = symbol->next;
		symbol->next = new;
	}
}

void	ft_lst_sorted_insert(t_symbol **head, t_symbol *new)
{
	t_symbol *symbol;

	if (*head == NULL || ft_strcmp((*head)->sym_name, new->sym_name) >= 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		symbol = *head;
		while (symbol->next
				&& ft_strcmp(symbol->next->sym_name, new->sym_name) < 0)
		{
			symbol = symbol->next;
		}
		new->next = symbol->next;
		symbol->next = new;
	}
}

void	print_symbol(t_symbol *symbol, void *string_table_ptr)
{
	t_symbol	*temp;

	temp = symbol;
	while (temp)
	{
		printf("%s @ %#010lx (%ld)\n", temp->sym_name, temp->sym_name - string_table_ptr, (temp->sym_name - string_table_ptr));
		temp = temp->next;
	}
}
