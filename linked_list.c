#include "push_swap.h"
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

// typedef struct	s_list
// {
// 	int				n;
// 	struct s_list	*next;
// 	struct s_list	*prev;
// }				t_list;

t_list	*ft_lstnew(int n)
{
	t_list *p;

	p = (t_list *)malloc(sizeof(t_list));
	p->n = n;
	p->next = p;
	p->prev = p;
	return p;
}

void	ft_lstclear(t_list **list)
{
	t_list	*ptr;
	t_list	*l;
	t_list	*last;

	if (!*list)
		return ;
	ptr = *list;
	l = *list;
	last = l->prev;
	while (ptr != last)
	{
		l = l->next;
		free(ptr);
		ptr = l;
	}
	free(last);
	*list = NULL;
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	if (!*list)
	{
		ft_lstadd_front(list, new);
		return ;
	}
	*list = (*list)->prev;
	ft_lstadd_front(list, new);
	*list = (*list)->prev;
}

void	ft_lstadd_front(t_list **list, t_list *new)
{
	t_list	*ptr;
	
	ptr = *list;
	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	new->next = ptr;
	new->prev = ptr->prev;
	ptr->prev->next = new;
	ptr->prev = new;
}

void	rev_print_list(t_list *lst)
{
	t_list	*first = lst;

	if (!lst)
		return ;
	lst = lst->prev;
	while (1)
	{
		printf("%d\n", lst->n);
		if (lst == first)
			break;
		lst = lst->prev;
	}
}

void	print_list(t_list *lst)
{
	t_list	*last = lst;

	if (!lst)
		return ;
	while (1)
	{
		printf("%d\n", lst->n);
		if (lst->next == last)
			break;
		lst = lst->next;
	}
}