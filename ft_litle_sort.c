#include "push_swap.h"

void sort_three(t_list **list_a, t_list **list_b)
{
	if (ft_checksorted(*list_a) == 1)
		return ;
	if (find_min(*list_a) == (*list_a)->n)
	{
		*list_a = reverse(*list_a);
		*list_a = swap(*list_a);
	}
	else if (find_max(*list_a) == (*list_a)->n)
	{
		*list_a = rotate(*list_a);
		if (!(ft_checksorted(*list_a) == 1))
			*list_a = swap(*list_a);
	}
	else
	{
		if (find_max(*list_a) == (*list_a)->next->n)
			*list_a = reverse(*list_a);
		else
			*list_a = swap(*list_a);
	}
}

void	extract_min(t_list **list_a, t_list **list_b)
{
	int		min;
	t_list*	(*op)(t_list*);

	
	min = find_min(*list_a);
	if (find_npos(*list_a, min) >= 2)
		op = &reverse;
	else
		op = &rotate;
	while ((*list_a)->n != min)
		*list_a = op(*list_a);
	push(list_b, list_a);
}

void	sort_four(t_list **list_a, t_list **list_b)
{
	extract_min(list_a, list_b);
	sort_three(list_a, list_b);
	push(list_a, list_b);
}

void	sort_five(t_list **list_a, t_list **list_b)
{
	extract_min(list_a, list_b);
	extract_min(list_a, list_b);
	if ((*list_a)->next->n < (*list_a)->prev->n)
	{

	}
	sort_three(list_a, list_b);
	push(list_a, list_b);
	push(list_a, list_b);
}

int	ft_litle_sort(t_list **list_a, t_list **list_b)
{
	if ((ft_checksorted(*list_a) == 1))
	{
		printf("******************SORTED****************\n");
		ft_lstclear(list_a);
		exit(0);
	}
	if (ft_lst_size(*list_a) == 3)
		sort_three(list_a, list_b);
	else if (ft_lst_size(*list_a) == 4)
		sort_four(list_a, list_b);
	else
		sort_five(list_a, list_b);
	return (0);
}

