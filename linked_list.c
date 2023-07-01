#include "push_swap.h"
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content)
{
	t_list *p;

	p = (t_list *)malloc(sizeof(t_list));
	p->content = content;
	p->next = NULL;
	return p;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void print_list(t_list **lst)
{
	t_list *temp = *lst;

	while (temp != NULL)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
}

int ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list *ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return NULL;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return lst;
}

int main()
{
	t_list	*p;
	t_list	*n;
	int		i;

	p = ft_lstnew("ligne 1");
	n = ft_lstnew("ligne 2");
	ft_lstadd_front(&p, n);
	n = ft_lstnew("ligne 3");
	ft_lstadd_front(&p, n);
	print_list(&p);
	i = ft_lstsize(p);
	printf("%d\n", i);
	return 0;
}