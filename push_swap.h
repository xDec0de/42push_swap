/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:31 by danimart          #+#    #+#             */
/*   Updated: 2025/03/09 19:36:19 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>
#include <stdio.h> // debug

typedef struct s_list
{
	int				content;
	bool			modified;
	struct s_list	*next;
}				t_list;

// push_swap.c
void	error(int code);
int		to_stack_send(long *res, char *sign, t_list **a);

/*
 - Stack manager
 */

/**
 * @brief `static` getter for stack a. If `init`
 * is not `NULL`, the `static` variable conatined on
 * this function will be set to `init`. Said variable
 * is always returned.
 * 
 * @param init The new value of stack a. Use `NULL` to
 * get the already stored value of stack a.
 * 
 * @return The stored value of stack a.
 */
t_list	*get_a(t_list *init);

/**
 * @brief `static` getter for stack b. If `init`
 * is not `NULL`, the `static` variable conatined on
 * this function will be set to `init`. Said variable
 * is always returned.
 * 
 * @param init The new value of stack b. Use `NULL` to
 * get the already stored value of stack b.
 * 
 * @return The stored value of stack b.
 */
t_list	*get_b(t_list *init);

/**
 * @brief Initializes a stack element (t_list) with the
 * default values. Program will `exit` with error code
 * `MALLOC_ERR` if `malloc` fails.
 * 
 * @param next The `next` element on the new struct. Can
 * be `NULL`.
 * 
 * @return A new `t_list` initialized with the default values
 * and `next` set as the next element of the list.
 */
t_list	*init_stack_element(t_list *next);

/**
 * @brief Frees all elements of both stacks. Stacks can be
 * `NULL`, the function will just skip them. The pointer
 * of each stack must be a pointer to its first element,
 * otherwise, leaks will be produced.
 * 
 * @param a A pointer to the first element of stack `a`.
 * @param b A pointer to the first element of stack `b`.
 */
void	free_stacks(t_list *a, t_list*b);

/**
 * @brief Handles program exit. Both stacks `a` and `b`
 * are safely freed as specified by `free_stacks`.
 * "Error\\n" will be written on `STDOUT_FILENO` if
 * the `exit_code` requires it.
 * 
 * @param a A pointer to the first element of stack `a`.
 * @param b A pointer to the first element of stack `b`.
 * @param exit_code The `exit` code of the program. Used
 * to indicate what error happened or if the program exited
 * with a successful execution.
 */
void	exit_ps(t_list *a, t_list *b, int exit_code);

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

/* 
 - Exit / error codes
 */

# define ERR_ARGC 1

# define ERR_ALREADY_SORTED 2

/** Malloc failed. Program exits with an error. */
# define ERR_MALLOC 3

#endif
