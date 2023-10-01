/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:13:25 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/01 20:12:08 by arnduran         ###   ########.fr       */
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
	list_a = NULL;
	n = parsing(argc, argv, &list_a);
	init_index(list_a);
	printf("-----------PARSING------------------------\n");
	print_list(list_a);
	printf("-----------------------------------\n");
	printf("-------------SWAP----------------------\n");
	print_list(list_a);
	printf("///////////////////SWAP-A//////////////////\n");
	printf("///////////////////LIST A //////////////////\n");
	print_list(list_a);
	printf("///////////////////LIST B//////////////////\n");
	print_list(list_b);
	printf("///////////////////TEST TAILLE LISTE//////////////////\n");
	printf("%lu\n", ft_lst_size(list_a));
	resolution(&list_a, &list_b);
	printf("~~~~~~~~~~~~~~~~~~~~LIST_B PUIS A~~~~~~~~~~~~~~~~\n");
	print_list(list_a);
	printf("~~~~~~~~~~~~~~~~~~~LIST A PUIS B~~~~~~~~~~~~~~~~~\n");
	print_list(list_b);
	ft_lstclear(&list_a);
	ft_lstclear(&list_b);
	return (0);
}
