/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:13:16 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/04 18:17:29 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "push_swap.h"

int	ft_isnbr(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (*s == 0);
}

int	double_check(t_list *list, int nb)
{
	t_list	*ptr;

	if (!list)
		return (1);
	ptr = list->next;
	while (1)
	{
		if (ptr->n == nb)
			return (0);
		if (ptr == list)
			break ;
		ptr = ptr->next;
	}
	return (1);
}

int	parsing(int argc, char **argv, t_list **list)
{
	int		i;
	long	num;
	t_list	*ptr;
	char	**av;

	i = 0;
	ptr = *list;
	av = ft_split(argv[1], ' ');
	while (av[i])
	{
		num = ft_atoi(av[i]);
		if (!ft_isnbr(av[i]) || errno == ERANGE
			|| double_check(*list, num) == 0)
		{
			ft_freetab(av);
			ft_lstclear(list);
			ft_error(-2);
		}
		ptr = ft_lstnew(num);
		ft_lstadd_front(list, ptr);
		i++;
	}
	ft_freetab(av);
	return (i);
}

unsigned int	find_index(t_list *list, int v)
{
	t_list			*last;
	unsigned int	i;

	i = 0;
	last = list;
	list = list->next;
	while (list != last)
	{
		if (list->n < v)
			i++;
		list = list->next;
	}
	return (i);
}

void	init_index(t_list *list)
{
	t_list	*last;

	if (!list)
		return ;
	last = list;
	while (1)
	{
		list->index = find_index(list, list->n);
		list = list->next;
		if (list == last)
			break ;
	}
}
