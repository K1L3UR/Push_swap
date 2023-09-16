# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

// typedef struct	Stack
// {
// 	int	*next;
// 	int	*previous;
// 	int	capacity;
// }Stack1, Stack2;

typedef	struct s_stack_a t_ska;

struct s_stack_a		// liste chainer a modifier plus tard pour une liste versatile
{
	int	n;
	t_ska *next;
};

typedef	struct	s_list
{
	t_ska	*ptr_lst; 	// pointeur vers la liste chainer
	t_ska	*head_ref;	// sauvegarde du debut de la liste chainer
	size_t	i;			// taille de la liste chainer dans la structure
}				t_list;


int		parsing(int argc, char **argv, t_ska **t_list);
int		ft_error(int n);
int		tab_size(char *str);
int		count_chained_list(t_ska *list);
t_ska	*add_link(t_ska *list, int nbr);
void	print_list(t_ska *list);
t_ska	*swap_a(t_list *bloc);

#endif