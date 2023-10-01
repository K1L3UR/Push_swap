/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:23:16 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/01 19:58:23 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "push_swap.h"

void	ft_freelist(t_list **list)
{
	t_list	*head;

	head = *list;
	while (*list)
	{
		(*list) = (*list)->next;
		free(*list);
	}
}

void	ft_freetab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

int	tab_size(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_error(int n)
{
	if (n == 0)
		exit(0);
	if (n == -1)
		exit((ft_putendl_fd("Wrong number of arguments", 2), -1));
	if (n == -2)
		exit((ft_putendl_fd("Error parsing", 2), -2));
	if (n == -3)
		exit((ft_putendl_fd("Error malloc", 2), -3));
	if (n == -4)
		exit(-4);
	if (n == -5)
		exit(-5);
	exit(EXIT_FAILURE);
}
