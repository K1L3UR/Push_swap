#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "push_swap.h"


int	tab_size(char	*str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	count_chained_list(t_ska *list)
{
	int		i;
	t_ska	*current;

	i = 0;
	current = list;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
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
		exit(-3);
	if (n == -4)
		exit(-4);
	if (n == -5)
		exit(-5);
	exit(EXIT_FAILURE);
}