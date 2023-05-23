#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int	check_list(char *str, int **tab)
{
	int	i;
	int	res;
	int	add;
	int	size;

	add = 0;
	res = 0;
	i = 0;
	size = 1;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
		{
			res = ft_atoi(&str[i]);
			size++;
			*tab = realloc(*tab, size * sizeof(int));
			while (ft_isdigit(str[i] == 1))
				i++;
		}
		else
			i++;
	}
	return (i);
}

// int check_list(char *str, int **tab)
// {
//     int i;
//     int res;
//     int size;

//     size = 0;
//     i = 0;
//     while (str[i] != '\0')
//     {
//         if (ft_isdigit(str[i]) == 1)
//         {
//             res = ft_atoi(&str[i]);
//             size++;
//             *tab = realloc(*tab, size * sizeof(int));
//             (*tab)[size - 1] = res;
//             while (ft_isdigit(str[i]) == 1)
//                 i++;
//         }
//         else
//             i++;
//     }
//     return i;
// }

int	main(int argc, char **argv)
{
	int	ret;
	int	*tab;

	ret = 0;
	if (argc != 2)
		ft_error(-1);
	//printf("%s\n", argv[1]);
	tab = (int*)malloc(sizeof(int) * 1);
	ret = check_list(argv[1], &tab);
	print_tab(tab);
	if (ret == -1)
		ft_error(-1);
	return (0);
}

//xrandr --output eDP --mode 2560x1440