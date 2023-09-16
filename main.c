#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

t_ska	*ft_lstlast(t_ska *lst)
{
	t_ska	*ptr = lst;

    if (lst == NULL)
    	return NULL;
    while (ptr->next != NULL)
    	ptr = ptr->next;
	return (ptr);
}

void print_list(t_ska *list)
{
	while (list != NULL)
	{
		ft_putnbr_fd(list->n, 1);
		ft_putchar_fd('\n', 1);
		list = list->next;
	}
}

t_ska *add_link(t_ska *list, int nbr)
{
	t_ska 	*ptr;

	ptr = malloc(sizeof(t_ska));
	if (!ptr)
		return (NULL);
	ptr->n = nbr;
	ptr->next = list;
	return (ptr);
}

int	main(int argc, char **argv)
{
	int		tab[] = {1, 2, 3, 4, 5, 6, 7};
	t_ska 	*list_a; // la seule liste qui recois la chaine de nombre
	t_list	p_struct;
	int		i;
	int		x;

	p_struct.i = 0;
	p_struct.ptr_lst = NULL;
	if (argc < 2)
		return (ft_error(-1));
	i = sizeof(tab) / sizeof(int);
	list_a = NULL;
	x = parsing(argc, argv, &list_a);
	p_struct.head_ref = ft_lstlast(list_a);
	p_struct.ptr_lst = list_a;
	p_struct.i = count_chained_list(list_a);
	print_list(list_a);
	printf("%d\n", p_struct.head_ref->n);
	//swap_a(&p_struct);
	printf("------------------------------------\n");
	print_list(list_a);
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