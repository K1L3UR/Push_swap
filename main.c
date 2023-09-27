#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

// t_ska	*ft_lstlast(t_ska *lst)
// {
// 	t_ska	*ptr = lst;

//     if (lst == NULL)
//     	return NULL;
//     while (ptr->next != NULL)
//     	ptr = ptr->next;
// 	return (ptr);
// }

// void print_list(t_ska *list)
// {
// 	while (list != NULL)
// 	{
// 		ft_putnbr_fd(list->n, 1);
// 		ft_putchar_fd('\n', 1);
// 		list = list->next;
// 	}
// }

// t_ska *add_link(t_ska *list, int nbr)
// {
// 	t_ska 	*ptr;

// 	ptr = malloc(sizeof(t_ska));
// 	if (!ptr)
// 		return (NULL);
// 	ptr->n = nbr;
// 	ptr->next = list;
// 	return (ptr);
// }

t_list	*ft_b(t_list **list_b)
{
	t_list	*ptr;

	ptr = ft_lstnew(8);
	ft_lstadd_front(list_b, ft_lstnew(8));
	return (*list_b);
}

int	main(int argc, char **argv)
{
	//int		tab[] = {1, 2, 3, 4, 5, 6, 7};
	t_list	*list_a; // la seule liste qui recois la chaine de nombre
	t_list	*list_b;
	t_list	*ptr;
	int		i;
	int		x;

	list_b = NULL;
	//ft_lstadd_front(&list_b, ft_lstnew(2));
	//ft_lstadd_front(&list_b, ft_lstnew(10));
	if (argc < 2)
		return (ft_error(-1));
	list_a = NULL;
	x = parsing(argc, argv, &list_a);
	ptr = list_a;
	printf("-----------------------------------\n");
	swap(list_a);
	// print_list(list_a);
	printf("///////////////////SWAP-A//////////////////\n");
	push_a_to_b(&list_a, &list_b);
	//print_list(list_a);
	// print_list(list_b);
	// printf("///////////////////LIST B AFTER PUSH B//////////////////\n");
	// swap(list_a);
	// print_list(list_a);
	// printf("///////////////////LIST_A//////////////////\n");
	// rotate(list_a);
	// print_list(list_a);
	// printf("///////////////////LIST_A//////////////////\n");
	// push_a(&list_a, &list_b);
	// printf("----------------LIST_A--------------------\n");
	// print_list(list_a);
	// printf("///////////////////LIST_A//////////////////\n");
	// printf("-------------------LIST_B-----------------\n");
	// //resolution(&list_a, &list_b);
	// printf("~~~~~~~~~~~~~~~~~~~~LIST_B PUIS A~~~~~~~~~~~~~~~~\n");
	// //print_list(list_a);
	// printf("~~~~~~~~~~~~~~~~~~~LIST A PUIS B~~~~~~~~~~~~~~~~~\n");
	// //print_list(list_b);
	// printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return (0);
}

// int	main()
// {
// 	int		tab[] = {1, 2, 3};
// 	t_ska 	*list;
// 	int		i;

// 	i = 3;
// 	list = NULL;
// 	while (i > 0)
// 	{
// 		list = add_link(list ,tab[i - 1] );
// 		i--;
// 	}
// 	print_list(list);
// }