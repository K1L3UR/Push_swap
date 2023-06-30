#include "push_swap.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list *ft_lstnew(void *content)
{
	t_list	*next;

	content = malloc(sizeof(content)); 
	next->content;
	return(content);
}

int	main()
{	 
	t_list	*p;

	p = ft_lstnew("string");
	printf ("%s\n", *p);
	return (0);
}