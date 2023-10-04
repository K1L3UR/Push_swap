/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:40:35 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/03 20:56:58 by arnduran         ###   ########.fr       */
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

/* #cette fonction sert a reverse la liste tel rra# */

t_list	*reverse_list(t_list *list)
{
	return (list->prev);
}