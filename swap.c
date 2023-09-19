#include "push_swap.h"

t_list	*swap(t_list *list)
{
	t_list	*ptr;
	t_list	*fuhrer;
	int		tmp;

	ptr = list;
	if (ptr->next == ptr->prev)
		return(list);
	fuhrer = ptr->next;
	tmp = ptr->n;
	ptr->n = fuhrer->n;
	fuhrer->n = tmp;
	return (list);
}

t_list	*rotate(t_list *list)
{
	return (list->next);
}

t_list	*reverse(t_list *list)
{
	return (list->prev);
}

void	push(t_list **list_a, t_list **list_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = *list_a;
	ptr_b = *list_b;
	if (!*list_b)
		return ;
	if ((*list_b)->next == (*list_b))
	{
		ft_lstadd_front(list_a ,ptr_b);
		*list_a = reverse(*list_a);
		*list_b = NULL;
		return ;
	}
	ptr_b->next->prev = ptr_b->prev;
	ptr_b->prev->next = ptr_b->next;
	*list_b = ptr_b->next;
	ft_lstadd_front(list_a, ptr_b);
	*list_a = reverse(*list_a);
	return ;
}