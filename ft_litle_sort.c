#include "push_swap.h"

void sort_three(t_list **list_a, t_list **list_b)
{
	t_list	*a;
	int		min;
	int		nextmin;
	int		max;
	
	a = *list_a;
	printf("========================LIST_BEFORE========================\n");
	print_list(*list_a);
	printf("========================STRATING========================\n");
	if (a == NULL || a->next == NULL || a->next->next == NULL)
		return;
	min = find_min(*list_a);
	printf("%dmin\n", min); //2
	nextmin = find_next_min(*list_a ,min);
	printf("%dnxmin\n", nextmin); //2
	//printf("%d\n", max); //8
	// printf("%d\n", nextmin); //4
	if ((ft_checksorted(*list_a) == 1))
		exit(0);
	print_list(*list_a);
	printf("========================SWAP A========================\n");
	printf("========================OPE SA========================\n");
	print_list(*list_a);
	printf("========================RRA========================\n");
	*list_a = reverse(*list_a);
	print_list(*list_a);
	printf("========================OPE RRA========================\n");
	// if (x > y && x > z)
	// {
	// 	printf("x > y && x > z\n");
	// 	if (y > z)
	// 	{
	// 	printf("if\n");
	// 		*list_a = reverse(*list_a); // z, y, x => x, y, z
	// 	}
	// 	else
	// 	{
	// 		printf("else\n");
	// 		*list_a = swap(*list_a); // y, z, x => z, y, x
	// 		*list_a = reverse(*list_a); // z, y, x => x, y, z
	// 	}
	// }
	// else if (y > x && y > z)
	// {
	// 	printf("y > x && y > z\n");
	// 	if (x > z)
	// 	{	
	// 		printf("if\n");
	// 		*list_a = swap(*list_a); // x, z, y => z, x, y
	// 	}
	// 	else
	// 	{
	// 		printf("else\n");
	// 		*list_a = rotate(*list_a); // z, x, y => y, x, z
	// 	}
	// }
	// else if (x > y)
	// {	
	// 	printf("x > y\n");
	// 	*list_a = swap(*list_a); // y, x, z => x, y, z
	// }
	print_list(*list_a);
	printf("========================SORT THREE========================\n");
	exit(1) ;
}


// void	sort_three(t_list *list_a, t_list *list_b)
// {
// 	if (find_min(list_a) == (list_a)->n)
// 	{
// 		reverse(list_a);
// 		list_a = swap(list_a);
// 	}
// 	else if (find_max(list_a) == (list_a)->n)
// 	{
// 		rotate(list_a);
// 		if (!ft_checksorted(list_a))
// 			list_a = swap(list_a);
// 	}
// 	else
// 	{
// 		if (list_a->n < list_a->next->next->n) //find_max(*list_a)) == 1)
// 			reverse(list_a);
// 		else
// 			list_a = swap(list_a);
// 	}
// 	printf("========================SORT THREE========================\n");
// 	print_list(list_a);
// 	exit(0);
// 	return ;
// }

void	sort_five(t_list **list_a, t_list **list_b)
{
	printf("SORT FIVE\n");
	return ;
}

int	ft_litle_sort(t_list **list_a, t_list **list_b)
{
	if ((ft_checksorted(*list_a) == 1))
	{
		printf("******************SORTED****************\n");
		exit(0);
	}
	if (ft_lst_size(*list_a) == 3)
		sort_three(list_a, list_b);
	else
		sort_five(list_a, list_b);
	return (0);
}

