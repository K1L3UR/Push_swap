#include "push_swap.h"

int	find_min(t_list **list_a)
{
	int		min;
	t_list	*last;

	last = *list_a;
	min = (*list_a)->n;
	if (*list_a)
		(*list_a) = (*list_a)->next;
	else
		return (ft_error(-1));
	while ((*list_a)->next != last)
	{
		if (min > (*list_a)->n)
			min = (*list_a)->n;
		(*list_a) = (*list_a)->next;
	}
	return (min);
}

int	resolution(t_list **list_a, t_list **list_b)
{
	int		min;
	t_list	*ptr_a;
	t_list	*ptr_b;
	
	min = 0;
	ptr_a = *list_a;
	ptr_b = *list_b;
	min = find_min(list_a);
	printf("%d\n", 10>>1);
	return (0);
}