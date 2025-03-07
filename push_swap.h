/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:31 by danimart          #+#    #+#             */
/*   Updated: 2025/03/07 17:48:43 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
#include <stdio.h> // debug

typedef struct s_list
{
	int				content;
	int				modified;
	struct s_list	*next;
}	t_list;

// push_swap.c
void	error(int code);
int		to_stack_send(long *res, char *sign, t_list **a);

// str_utils.c
int		ft_isdigit(int c);
void	ft_bzero(void	*str, size_t n);
void	*ft_calloc(size_t count, size_t size);

// list_utils.c
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstmin_unmod(t_list *lst);

// sort_utils.c
void	simplify_stack(t_list **a, int size);
int		get_div_size(int size);
void	lowest_a_to_b(t_list **a, t_list **b);

// input_checker.c
void	to_stack_check(const char *str, t_list **a);
void	check_numeric(int argc, char **a);
int		check_sorted(t_list *a);
int		check_duplicates(t_list *a);

// swap_func.c
int		swap_a(t_list **a, int print);
int		swap_b(t_list **b, int print);
int		swap_ab(t_list **a, t_list **b);

// push_func.c
int		push_a(t_list **a, t_list **b);
int		push_b(t_list **a, t_list **b);

// rotate_func.c
int		rotate_a(t_list **a, int print);
int		rotate_b(t_list **a, int print);
int		rotate_ab(t_list **a, t_list **b);

// rev_rotate_func.c
int		rev_rotate_a(t_list **a, int print);
int		rev_rotate_b(t_list **b, int print);
int		rev_rotate_ab(t_list **a, t_list **b);

// sort_func.c
void	sort(t_list **a, t_list **b, int size);
void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b, int size);
void	sort_all(t_list **a, t_list **b, int size);

// full_sort_utils.c
void	send_b_easiest(t_list **a, t_list **b, int min, int max);
void	send_b_to_a(t_list **a, t_list **b);

// debug //

void	print_stacks(t_list *a, t_list *b);
void	test_rev_rotate(t_list **a, t_list **b);

#endif
