/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:13:33 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/01 19:13:48 by arnduran         ###   ########.fr       */
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
	return (list);
}

/* rotate (ra)*/

t_list	*rotate(t_list *list)
{
	return (list->next);
}

/* je suis reverse rotate (rra)*/

t_list	*reverse(t_list *list)
{
	return (list->prev);
}

void	push(t_list **dst, t_list **src)
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
		*dst = reverse(*dst);
		*src = NULL;
		return ;
	}
	ptr_src->next->prev = ptr_src->prev;
	ptr_src->prev->next = ptr_src->next;
	*src = ptr_src->next;
	ptr_src->prev = ptr_src;
	ptr_src->next = ptr_src;
	ft_lstadd_front(dst, ptr_src);
	*dst = reverse(*dst);
}
