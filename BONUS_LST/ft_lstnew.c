#include "lst.h"
#include <stdlib.h>

// t_list *ft_lstnew(void *content)
// {
// 	t_list	*elem;

// 	elem = malloc(sizeof(t_list);
// 	elem->content = content;
// 	elem->next = NULL;
// 	return (elem);	
// }

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

// int	count_chained_list(t_list	*list)
// {
// 	int		i;
// 	t_list	*current;

// 	i = 0;
// 	current = list;
// 	while (current != NULL)
// 	{
// 		i++;
// 		current = current->next;
// 	}
// 	return (i);
// }

// int	main()
// {
// 	t_list	*list;

// 	list = NULL;
// 	list = ft_lstnew("bonjour");
// 	printf("%d\n", count_chained_list(list));
// 	printf("%s\n", (char*)list->content);
// 	return (0);
// }