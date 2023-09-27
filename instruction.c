#include "push_swap.h"

t_list	*swap(t_list *list) // a tester pour ss (swap a et swap b)
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

void	push_a_to_b(t_list **list_a, t_list **list_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = *list_a;
	ptr_b = *list_b;
	printf("------------------------------\n");
	printf("%d\n", ptr_a->n);
	printf("------------------------------\n");
	if (!*list_a)
		return ;
	printf("------------------------------------\n");
	if ((*list_a)->next == (*list_a))
	{
		ft_lstadd_front(list_b ,ptr_a);
		*list_b = reverse(*list_b);
		*list_a = NULL;
		return ;
	}
	ptr_a->next->prev = ptr_a->prev; //ptr_a->next->prev = ptr_a->prev
	ptr_a->prev->next = ptr_a->next;
	*list_a = ptr_a->next;
	ft_lstadd_front(list_b, ptr_a);
	//ft_lstadd_front(list_b, (*list_a));
	*list_b = reverse(*list_b);
	printf("------------------------------------\n");
	print_list(*list_a);
	return ;
}

void	push_b_to_a(t_list **list_a, t_list **list_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;

	ptr_a = *list_a;
	ptr_b = *list_b;
	if (!*list_b)
		return ;
	printf("------------------------------\n");
	printf("%d\n", ptr_b->n);
	printf("------------------------------\n");
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
	print_list(*list_a);
	printf("------------------------------------\n");
	print_list(*list_b);
	return ;
}