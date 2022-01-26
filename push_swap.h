/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:31 by danimart          #+#    #+#             */
/*   Updated: 2022/01/26 17:12:51 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXTENDED_ERROR 1

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
#include <stdio.h> // debug

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
void	ft_bzero(void	*str, size_t n);
void	*ft_calloc(size_t count, size_t size);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstcpy(t_list *origin, t_list **copy);
void	to_stack_check(const char *str, t_list **a);
void	check_numeric(int argc, char **a);
int		check_sorted(t_list *a);
void	error(int code);
int		to_stack_send(long *res, char *sign, t_list **a);
int		check_duplicates(t_list *a);
void	swap_a(t_list **a, int print);
void	swap_b(t_list **b, int print);
void	swap_ab(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a, int print);
void	rotate_b(t_list **a, int print);
void	rotate_ab(t_list **a, t_list **b);
void	rev_rotate_a(t_list **a, int print);
void	rev_rotate_b(t_list **b, int print);
void	rev_rotate_ab(t_list **a, t_list **b);
void	send_lowest(t_list **from, t_list **to, char stack);

// debug //

void	print_stacks(t_list *a, t_list *b);
void	test_swap(t_list **a, t_list **b);
void	test_push(t_list **a, t_list **b);
void	test_reverse(t_list **a, t_list **b);
void	test_rotate(t_list **a, t_list **b);
void	test_rev_rotate(t_list **a, t_list **b);

// test //

void	test_sort(t_list **a, t_list **b, int size);
void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b, int size);
void	sort_all(t_list **a, t_list **b, int size);

#endif