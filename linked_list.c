/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:13:03 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/05 16:53:01 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(int n)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	p->n = n;
	p->index = 0;
	p->next = p;
	p->prev = p;
	return (p);
}

void	ft_lstclear(t_list **list)
{
	t_list	*ptr;
	t_list	*l;
	t_list	*last;

	if (!*list)
		return ;
	ptr = *list;
	l = *list;
	last = l->prev;
	while (ptr != last)
	{
		l = l->next;
		free(ptr);
		ptr = l;
	}
	free(last);
	*list = NULL;
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	if (!*list)
	{
		ft_lstadd_front(list, new);
		return ;
	}
	*list = (*list)->prev;
	ft_lstadd_front(list, new);
	*list = (*list)->prev;
}

void	ft_lstadd_front(t_list **list, t_list *new)
{
	t_list	*ptr;

	ptr = *list;
	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	new->next = ptr;
	new->prev = ptr->prev;
	ptr->prev->next = new;
	ptr->prev = new;
}

size_t	ft_lst_size(t_list *list)
{
	t_list	*ptr_a;
	size_t	i;

	if (!list)
		return (0);
	ptr_a = list;
	i = 0;
	while (1)
	{
		ptr_a = ptr_a->next;
		i++;
		if (ptr_a == list)
			return (i);
	}
	return (i);
}
