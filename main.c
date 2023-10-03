/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:13:25 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/03 21:59:42 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		i;
	int		n;

	list_b = NULL;
	i = 1;
	if (argc < 2)
		return (ft_error(-1));
	if (argv[1][0] == 0) // gere le "" cas
		ft_error(-2);
	list_a = NULL;
	n = parsing(argc, argv, &list_a);
	init_index(list_a);
	printf("-----------PARSING------------------------\n");
	resolution(&list_a, &list_b);
	printf("~~~~~~~~~~~~~~~~~~~~LIST_A~~~~~~~~~~~~~~~~\n");
	print_list(list_a);
	printf("~~~~~~~~~~~~~~~~~~~LIST_B~~~~~~~~~~~~~~~~~\n");
	print_list(list_b);
	ft_lstclear(&list_a);
	ft_lstclear(&list_b);
	return (0);
}
