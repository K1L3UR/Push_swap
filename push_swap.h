/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 19:20:53 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/05 19:47:16 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"

typedef enum bool {true, false}	t_bool;

typedef struct s_list
{
	int				n;
	unsigned int	index;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int				parsing(int argc, char **argv, t_list **t_list);
int				ft_error(int n);
int				tab_size(char *str);
int				count_chained_list(t_list *list);
t_list			*add_link(t_list *list, int nbr);
void			print_list(t_list *list);
t_list			*swap(t_list *list);
t_list			*ft_lstnew(int n);
void			ft_lstclear(t_list **list);
void			ft_lstadd_front(t_list **list, t_list *new);
void			print_list(t_list *lst);
void			rev_print_list(t_list *lst);
void			ft_lstadd_back(t_list **list, t_list *new);
int				resolution(t_list **list_a, t_list **lists_b);
size_t			ft_lst_size(t_list *list_a);
t_list			*reverse(t_list *list);
t_list			*rotate(t_list *list);
void			push(t_list **dst, t_list **src, int bool);
void			init_index(t_list *list);
unsigned int	find_index(t_list *list, int v);
void			ft_freetab(char **tab);
void			ft_freelist(t_list **list);
int				ft_litle_sort(t_list **list_a, t_list **list_b);
int				find_max(t_list *list);
int				find_min(t_list *list);
int				find_next_min(t_list *list, int nb);
int				ft_checksorted(t_list *list_a);
int				find_npos(t_list *l, int n);
t_list			*reverse_list(t_list *list);
void			argv_parser(int *i, char **av, t_list **list, int argc);
int				ft_isnbr(const char *s);
int				double_check(t_list *list, int nb);

#endif