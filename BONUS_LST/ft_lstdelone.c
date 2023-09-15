#include "lst.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	// je dois del le mailons puis remettre la chaine
}


int	main()
{
	t_list *lst;
	t_list *head;
	
	lst = ft_lstnew("premier");
	head = lst;
	ft_lstadd_front(&lst, "premier");
	return (0);
}