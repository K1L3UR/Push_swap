/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:40:35 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/02 19:28:06 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_min(t_list *list, int nb)
{
	int		min;
	t_list	*last;

	if (!list)
		return (ft_error(-1));
	last = list;
	min = list->n;
	list = list->next;
	while (list->next != last)
	{
		if (min > list->n)
		{	
			if (min > nb)
				min = list->n;
		}
		list = list->next;
	}
	return (min);
}

int ft_middle(int a, int b, int c)
{
	if ((a >= b && a <= c) || (a >= c && a <= b))
		return a;
	else if ((b >= a && b <= c) || (b >= c && b <= a))
		return b;
	else
	return c;
}

int ft_min(int a, int b, int c)
{
	int min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;

	return min;
}

int ft_max(int a, int b, int c)
{
	int max = a;

	if (b > max)
		max = b;
	if (c > max)
		max = c;

	return max;
}
