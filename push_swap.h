# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

// typedef	struct s_stack_a t_ska;

// struct s_stack_a		// liste chainer a modifier plus tard pour une liste versatile
// {
// 	int	n;
// 	t_ska *next;
// };

// typedef	struct	s_list
// {
// 	t_ska	*ptr_lst; 	// pointeur vers la liste chainer
// 	t_ska	*head_ref;	// sauvegarde du debut de la liste chainer
// 	size_t	i;			// taille de la liste chainer dans la structure
// }				t_list;

typedef struct	s_list
{
	int				n;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int		parsing(int argc, char **argv, t_list **t_list);
int		ft_error(int n);
int		tab_size(char *str);
int		count_chained_list(t_list *list);
t_list	*add_link(t_list *list, int nbr);
void	print_list(t_list *list);
t_list	*swap(t_list *list);
t_list	*ft_lstnew(int n);
void	ft_lstclear(t_list **list);
void	ft_lstadd_front(t_list **list, t_list *new);
void	print_list(t_list *lst);
void	rev_print_list(t_list *lst);
void	ft_lstadd_back(t_list **list, t_list *new);
int		resolution(t_list **list_a, t_list **lists_b);
size_t	ft_lst_size(t_list *list_a);
t_list	*reverse(t_list *list);
t_list	*rotate(t_list *list);
void	push(t_list **dst, t_list **src);

#endif