#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

typedef struct	s_list
{
	void *content;
	struct s_list *next;
}				t_list;

// ADDITIONAL FUNCTION TO MAKE IT WORK 

void print_list(t_list *list);
int	count_chained_list(t_list	*list);

// END OF ADDITIONAL FUNCTION

t_list *ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));