/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:40:35 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/05 16:40:35 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_npos(t_list *l, int n)
{
	int	pos;

	pos = 0;
	while (l->n != n)
	{
		pos++;
		l = l->next;
	}
	return (pos);
}

t_list	*reverse_list(t_list *list)
{
	return (list->prev);
}

void	print_list(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!lst)
		return ;
	while (1)
	{
		printf("%d %p %p %p %d \n", lst->n, lst->prev, lst, lst->next, lst->index);
		if (lst->next == last)
			break ;
		lst = lst->next;
	}
}
