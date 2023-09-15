#include "lst.h"

// void ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list *ptr;

// 	ptr = NULL;
// 	if (*lst && new != NULL)
// 	{
// 		if (new)
// 		{
// 			ptr = ft_lstlast(*lst);
// 			ptr->next = new;
// 		}	
// 	}
// }

void ft_lstadd_back(t_list **lst, t_list *new)
{
    if (new != NULL)
    {
        if (*lst == NULL)
            *lst = new;
        else
        {
            t_list *ptr = ft_lstlast(*lst);
            ptr->next = new;
        }
    }
}

int	main()
{
	t_list	*list;
	t_list	*head;
	t_list	*new;

	list = NULL;
	new = NULL;
	list = ft_lstnew("premier");
	head = list;
	new = ft_lstnew("deuxieme");
	ft_lstadd_front(&head, new);
	new = ft_lstnew("troisieme");
	ft_lstadd_front(&head, new);
	new = ft_lstnew("quatrieme");
	ft_lstadd_front(&head, new);
	new = ft_lstnew("cinquieme");
	ft_lstadd_front(&head, new);
	new = ft_lstnew("zero");
	ft_lstadd_back(&head ,new);
	printf("%d\n", ft_lstsize(head));
	print_list(head);
	//printf("%s\n", (char*)head->content);
	return (0);
}