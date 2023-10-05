/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:12:49 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/05 16:52:52 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *list)
{
	int		min;
	t_list	*last;

	if (!list)
		return (ft_error(-1));
	last = list;
	min = list->n;
	list = list->next;
	while (list != last)
	{
		if (min > list->n)
			min = list->n;
		list = list->next;
	}
	return (min);
}

int	find_max(t_list *list)
{
	int		max;
	t_list	*last;

	if (!list)
		return (ft_error(-1));
	last = list;
	max = list->n;
	list = list->next;
	while (list != last)
	{
		if (max < list->n)
			max = list->n;
		list = list->next;
	}
	return (max);
}

int	find_digit(int max)
{
	int	i;
	int	max_bits;

	max_bits = 0;
	i = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	max_bits = find_digit(ft_lst_size(*stack_a) - 1);
	size = ft_lst_size(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				(*stack_a) = rotate((*stack_a));
			else
				push(stack_b, stack_a, false);
		}
		while (ft_lst_size(*stack_b) > 0)
			push(stack_a, stack_b, true);
		i++;
	}
}

int	resolution(t_list **list_a, t_list **list_b)
{
	int		max;
	int		min;
	int		digit;
	t_list	*ptr_a;
	t_list	*ptr_b;

	max = 0;
	ptr_a = *list_a;
	ptr_b = *list_b;
	if (ft_lst_size(*list_a) <= 5)
	{
		ft_litle_sort(list_a, list_b);
		return (0);
	}
	max = find_max(*list_a);
	min = find_min(*list_a);
	radix_sort(list_a, list_b, min, max);
	return (0);
}
