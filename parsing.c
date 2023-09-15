#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

void double_check(t_ska *list, int nb)
{
	t_ska *ptr;

	ptr = NULL;
	//ptr = list;
	ptr = ptr->next;
	while (ptr->next != NULL)
	{
		printf("%d\nnb :", ptr->n);
		if (ptr->n = nb)
			ft_error(-2);
		else
			ptr = ptr->next;
	}
}

int parsing(int argc, char **argv, t_ska **list)
{
	int i;
	int num;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9' || argv[1][i] == ' ') // utiliser l'atoi special ici
		{
			num = ft_atoi(&argv[1][i]); // utiliser un atoi special car je dois stocker "+1 2 -3" et enlever les doublons
			*list = add_link(*list, num);
			i++;
			double_check(*list, num);
			while (argv[1][i] >= '0' && argv[1][i] <= '9')
				i++;
		}
		else
			ft_error(-2);
	}
	return (i);
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