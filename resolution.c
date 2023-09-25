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

int	find_max(t_list **list_a)
{
	int		max;
	t_list	*last;

	last = *list_a;
	max = (*list_a)->n;
	if (*list_a)
		(*list_a) = (*list_a)->next;
	else
		return (ft_error(-1));
	while ((*list_a) != last)
	{
		//printf("%d\n|----|", (*list_a)->n);
		if (max < (*list_a)->n)
			max = (*list_a)->n;
		(*list_a) = (*list_a)->next;
	}
	return (max);
}

int	find_digit(int max)
{
	int	i;
	int	max_bits;

	max_bits = 0;
	i = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

// int	radix(t_list **list_a, t_list **list_b, int max_bits, int max)
// {
// 	int	i;
// 	int	j;
// 	int	n;
// 	int	size;

// 	size = ft_lst_size(list_a);
// 	n = 0;
// 	i = 0;
// 	j = 0;
// 	while ((max >> max_bits) != 0)
// 	{
// 		while (i < max_bits)
// 		{
// 			i++;
// 			while (j < size) // list size i assume
// 			{
// 				j++;
// 				n = (*list_a)->n;
// 				if (((n >> i) & 1) == 1)
// 					reverse(*list_a);
// 				else
// 					push(list_b, list_a);
// 			}
// 			while (!(*list_b))
// 				push(list_a, list_b); // ici
// 		}
// 	}
// 	return (0);
// }

void	radix_sort(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lst_size(stack_a);
	max_bits = find_digit(max);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((min >> i) & 1) == 1)
			{
				(*stack_a) = reverse((*stack_a));
				printf("REVERSE BOUCLE\n");
			}
			else
			{	
				push(stack_b, stack_a);
				printf("PUSH A TO B BOUCLE\n");			
			}
		}
		while (ft_lst_size(stack_b) != 0)
		{
			push(stack_a, stack_b);
			printf("PUSH B TO A BOUCLE\n");
		}
		i++;
	}
}

int	resolution(t_list **list_a, t_list **list_b)
{
	int		max;
	int		min;
	int		digit;
	t_list	*ptr_a;
	t_list	*ptr_b;
	
	max = 0;
	ptr_a = *list_a;
	ptr_b = *list_b;
	max = find_max(list_a);
	min = find_min(list_a);
	// printf("%d\n", 10>>1);
	//printf("%d\n", max);	
	//digit = find_digit(max);
	//printf("%d\n", digit);
	// radix(list_a, list_b, digit, max);
	radix_sort(list_a, list_b, min, max);
	return (0);
}