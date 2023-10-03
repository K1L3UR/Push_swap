/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:13:16 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/03 22:04:44 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "push_swap.h"

int		ft_isnbr(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (*s == 0);
}

void	double_check(t_list *list, int nb)
{
	t_list	*ptr;

	if (!list)
		return ;
	ptr = list->next;
	while (1)
	{
		if (ptr->n == nb)
			ft_error(-2);
		if (ptr == list)
			break;
		ptr = ptr->next;
	}
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
		num = ft_atoi(av[i]); // checker que je recois des chiffres
		if (!ft_isnbr(av[i]) || errno == ERANGE)
		{
			ft_freetab(av);
			ft_error(-2);
		}
		ptr = ft_lstnew(num);
		double_check(*list, num);
		ft_lstadd_front(list, ptr);
		i++;
	}
	ft_freetab(av);
	return (i);
}

/*
int parsing(int argc, char **argv, t_list **list)
{
	int		i;
	int		num;
	t_list	*ptr;

	i = 0;
	ptr = *list;
	while (argv[1][i] != '\0')
	{
		// if (ft_isdigit(argv[1][i]) || argv[1][i] == ' ' || argv[1][i] == '-') // utiliser l'atoi special ici
		if (ft_atoi(&argv[1][i]))
		{
			num = ft_atoi(&argv[1][i]); // utiliser un atoi special car je dois stocker "+1 2 -3" et enlever les doublons
			ptr = ft_lstnew(num);
			ft_lstadd_front(list, ptr);
			double_check(*list, num);
			i++;
			while (ft_isdigit(argv[1][i]))
				i++;
		}
		else
			ft_error(-2);
	}
	return (i);
}
*/

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
