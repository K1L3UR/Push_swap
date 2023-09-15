#include "lst.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_list *ft_lstlast(t_list *lst)
{
    if (lst == NULL)
    	return NULL;
    t_list *ptr = lst;
    while (ptr->next != NULL)
    	ptr = ptr->next;
	return ptr;
}

void print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%s\n", ((char*)list->content));
		list = list->next;
	}
}

t_list *ft_lstnew(void *content)
{
    t_list *elem;

    elem = malloc(sizeof(t_list));
    if (!elem)
        return (NULL);
    elem->content = malloc(sizeof(content));
    if (!elem->content)
    {
        free(elem);
        return (NULL);
    }
    memcpy(elem->content, content, sizeof(content));
    elem->next = NULL;
    return (elem);
}

int	count_chained_list(t_list	*list)
{
	int		i;
	t_list	*current;

	i = 0;
	current = list;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

// int	main()
// {
// 	t_list	*list;
// 	t_list	*head;

// 	list = NULL;
// 	head = NULL;
// 	ft_lstadd_front(&head, ft_lstnew("last"));
// 	list = head;
// 	ft_lstadd_front(&head, ft_lstnew("hello"));
// 	ft_lstadd_front(&head, ft_lstnew("bonjour"));
// 	printf("%d\n", count_chained_list(head));
// 	if (head != NULL)
// 		printf("%s\n", (char*)head->content);
// 	list = ft_lstlast(list);
// 	printf("%s\n", (char*)list->content);
// 	return (0);
// }
