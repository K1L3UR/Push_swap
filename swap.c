#include "push_swap.h"

t_list	*swap_a(t_list *list)
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

t_list	*rotate_a(t_list *list)
{
	return (list->next);
}

t_list	*reverse(t_list *list)
{
	return (list->prev);
}

void	push_a(t_list **list_a, t_list **list_b)
{
	t_list	*ptr_a;
	t_list	*ptr_b;
	t_list	*tmp;

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
	ft_lstadd_front(list_a, ptr_b);
	*list_a = reverse(*list_a);
	return ;
}

// t_list	*swap_a(t_list *list)
// {
// 	t_list	*ptr;
// 	t_list	*tmp;
// 	t_list	*p;

// 	p = list;
// 	if (!p || p->next == NULL)
// 		return (p);
// 	while (p->next->next != NULL)
// 	{
// 		//printf("%d\n", list->n);
// 		//printf("||||||||||||||||||||||\n");
// 		ptr = p;
// 		p = p->next;
// 	}
// 		printf("---------\n");
// 		printf("%d\n", p->next->n); // 1
// 		printf("---------\n");
// 		printf("%d\n", ptr->n); // 3
// 		printf("---------\n");
// 		printf("%d\n", p->n); // 2
// 		printf("---------\n");
// 	tmp = p;
// 	p= ptr->next;
// 	ptr->next = tmp;
// 	return (p);
// }