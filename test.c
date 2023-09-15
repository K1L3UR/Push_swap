#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

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
	t_skb	*list_b; // pour le moment elle est vide
	t_ska	*head_a; // sauvegarde du debut de la chaine liste_a
	int		i;
	int		x;
	
	if (argc < 2)
		return (ft_error(-1));
	i = sizeof(tab) / sizeof(int);
	list_a = NULL;
	list_b = NULL;
	x = parsing(argc, argv, &list_a);
	head_a = list_a;
	i = count_chained_list(head_a);
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