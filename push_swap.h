# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef struct	Stack
{
	int	*next;
	int	*previous;
	int	capacity;
}Stack1, Stack2;

int		ft_error(int n);
void	print_tab(int *tab);

#endif