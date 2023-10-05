/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:40:35 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/05 19:43:34 by arnduran         ###   ########.fr       */
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

void	argv_parser(int *i, char **av, t_list **list, int argc)
{
	long	num;
	t_list	*ptr;

	ptr = *list;
	num = ft_atoi(av[*i]);
	if (!ft_isnbr(av[*i]) || errno == ERANGE
		|| double_check(*list, num) == 0)
	{
		if (argc == 2)
			ft_freetab(av);
		ft_lstclear(list);
		ft_error(-2);
	}
	ptr = ft_lstnew(num);
	ft_lstadd_front(list, ptr);
	(*i)++;
}

/*
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
*/