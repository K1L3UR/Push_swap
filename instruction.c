/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:13:33 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/04 18:11:20 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*swap(t_list *list)
{
	t_list			*ptr;
	t_list			*fuhrer;
	int				tmp;
	unsigned int	mpt;

	ptr = list;
	if (ptr->next == ptr->prev)
		return (list);
	fuhrer = ptr->next;
	tmp = ptr->n;
	ptr->n = fuhrer->n;
	fuhrer->n = tmp;
	mpt = ptr->index;
	ptr->index = fuhrer->index;
	fuhrer->index = mpt;
	ft_putstr_fd("sa\n", 1);
	return (list);
}

/* rotate (ra)*/

t_list	*rotate(t_list *list)
{
	ft_putstr_fd("ra\n", 1);
	return (list->next);
}

t_list	*reverse(t_list *list)
{
	ft_putstr_fd("rra\n", 1);
	return (list->prev);
}

void	push(t_list **dst, t_list **src, int bool)
{
	t_list	*ptr_dst;
	t_list	*ptr_src;

	ptr_dst = *dst;
	ptr_src = *src;
	if (!*src)
		return ;
	if ((*src)->next == (*src))
	{
		ft_lstadd_front(dst, ptr_src);
		*dst = reverse_list(*dst);
		*src = NULL;
		return ;
	}
	ptr_src->next->prev = ptr_src->prev;
	ptr_src->prev->next = ptr_src->next;
	*src = ptr_src->next;
	ptr_src->prev = ptr_src;
	ptr_src->next = ptr_src;
	ft_lstadd_front(dst, ptr_src);
	*dst = reverse_list(*dst);
	if (bool == true)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}
