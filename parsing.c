#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void double_check(t_list *list, int nb)
{
	t_list *ptr;

	ptr = NULL;
	//ptr = list;
	ptr = ptr->next;
	while (ptr->next != NULL)
	{
		//printf("%d\nnb :", ptr->n);
		if (ptr->n == nb) // forcement vrai, je dois check le maillon d'apres dans la liste chaine
			ft_error(-2);
		else
			ptr = ptr->next;
	}
}

int parsing(int argc, char **argv, t_list **list)
{
	int		i;
	int		num;
	t_list	*ptr;

	i = 0;
	ptr = *list;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9' || argv[1][i] == ' ') // utiliser l'atoi special ici
		{
			num = ft_atoi(&argv[1][i]); // utiliser un atoi special car je dois stocker "+1 2 -3" et enlever les doublons
			ptr = ft_lstnew(num);
			ft_lstadd_front(list, ptr);
			i++;
			while (argv[1][i] >= '0' && argv[1][i] <= '9')
				i++;
		}
		else
			ft_error(-2);
	}
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
			break;
	}
}

// int	*parsing(int argc, char **argv, int *tab)
// {
// 	int	i;

// 	i = 0;
// 	while (argv[1][i] != '\0')
// 	{
// 		if (argv[1][i] >= '0' && argv[1][i] <= '9' || argv[1][i] == ' ')
// 			i++;
// 		else
// 			ft_error(-2);
// 	}
// 	tab = malloc((sizeof(int) * i) + 1);
// 	return (tab);
// }