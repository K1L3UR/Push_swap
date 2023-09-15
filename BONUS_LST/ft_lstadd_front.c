#include "lst.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	//t_list	*ptr;

	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
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

int ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		i;

	i = 0;
	current = lst;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
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

void print_list(t_list *list)
{
	while (list != NULL)
	{
		printf("%s\n", ((char*)list->content));
		list = list->next;
	}
}

// int	main()
// {
// 	t_list	*list;
// 	t_list	*head;
// 	t_list	*new;

// 	list = NULL;
// 	new = NULL;
// 	list = ft_lstnew("bonjour");
// 	head = list;
// 	new = ft_lstnew("nouveau");
// 	ft_lstadd_front(&head, new);
// 	printf("%d\n", ft_lstsize(head));
// 	print_list(head);
// 	//printf("%s\n", (char*)head->content);
// 	return (0);
// }