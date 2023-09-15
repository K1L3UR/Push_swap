#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	parsing(int argc, char **argv, t_ska **list)
{
	int	i;
	int	num;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9' || argv[1][i] == ' ')
		{
			num = ft_atoi(&argv[1][i]);
			*list = add_link(*list, num);
			i++;
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