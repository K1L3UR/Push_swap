#include "push_swap.h"

// t_ska	*swap_a(t_ska *list)
// {
// 	t_ska	*ptx;
// 	t_ska	*tmp;

// 	printf("---------\n");
// 	printf("%d\n", list->n);
// 	printf("---------\n");
// 	if (!list || list->next == NULL)
// 		return (list);
// 	while (list->next->next != NULL)
// 	{
// 		list = list->next;
// 	}
// 	ptx = list->next;
// 	printf("---------\n");
// 	printf("%d\n", list->n);
// 	printf("---------\n");
// 	printf("---------\n");
// 	printf("%d\n", ptx->n);
// 	printf("---------\n");
// 	tmp = ptx;
// 	ptx = list;
// 	list = tmp;
// 	return(list);
// }

t_ska   *swap_a(t_list *bloc)
{
	t_ska	*ptr;
	t_ska	*tmp;
	t_list	*p;

	p = bloc;
	if (!p->ptr_lst || p->ptr_lst->next == NULL)
		return (p->ptr_lst);
	while (p->ptr_lst->next->next != NULL)
	{
		//printf("%d\n", list->n);
		//printf("||||||||||||||||||||||\n");
		ptr = p->ptr_lst;
		p->ptr_lst = p->ptr_lst->next;
	}
		printf("---------\n");
		printf("%d\n", p->ptr_lst->next->n); // 1
		printf("---------\n");
		printf("%d\n", ptr->n); // 3
		printf("---------\n");
		printf("%d\n", p->ptr_lst->n); // 2
		printf("---------\n");
	// 
	// tmp = p->ptr_lst;
	// p->ptr_lst= ptr->next;
	// ptr->next = tmp;
	// tmp = p->ptr_lst;
	return (p->ptr_lst);
}