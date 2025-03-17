/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:31 by danimart          #+#    #+#             */
/*   Updated: 2025/03/17 16:53:01 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* unistd - Used for write */
# include <unistd.h>

/* stdlib - Used for malloc & free */
# include <stdlib.h>

/* limits - Used for min/max value macros */
# include <limits.h>

/* stdbool - Used for the bool type */
# include <stdbool.h>

typedef struct s_list
{
	int				content;
	bool			modified;
	struct s_list	*next;
}				t_list;

/*
 - Stack provider
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

/*
 - List utility
 */

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
t_list	*ps_lstinit(int content, t_list *next);

int		ps_lstsize(t_list *lst);

t_list	*ps_lstlast(t_list *lst);

void	ps_lstadd_back(t_list **lst, t_list *new);

t_list	*ps_lstmin_unmod(t_list *lst);

/*
 - Exit utility
 */

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
void	ps_exit(t_list *a, t_list *b, int exit_code);

/*
 - Input parsing
 */

t_list	*input_to_a(int argc, char **args);

/*
 - Movements - Push
 */

int		push_a(t_list **a, t_list **b);

int		push_b(t_list **a, t_list **b);

/*
 - Movements - Reverse Rotate
 */

int		rev_rotate_a(t_list **a, bool print);

int		rev_rotate_b(t_list **b, bool print);

int		rev_rotate_ab(t_list **a, t_list **b);

/*
 - Movements - Rotate
 */

int		rotate_a(t_list **a, bool print);

int		rotate_b(t_list **a, bool print);

int		rotate_ab(t_list **a, t_list **b);

/*
 - Movements - Swap
 */

int		swap_a(t_list **a, bool print);

int		swap_b(t_list **b, bool print);

int		swap_ab(t_list **a, t_list **b);

/*
 - Utils
 */

bool	ps_isdigit(char ch);

/**
 * @brief `malloc` wrapper used to exit the program
 * and free both stacks if `malloc` fails. Other than
 * that, this function is simply `malloc`.
 * 
 * @param size The amount of bytes to allocate.
 * 
 * @return A pointer to the allocated memory.
 */
void	*ps_malloc(int size);

/*
 - Sorting - Full
 */

void	full_sort(t_list **a, t_list **b, int size);

int		get_pos(t_list *lst, int value);

void	simplify_stack(t_list **a, int size);

void	send_b_easiest(t_list **a, t_list **b, int min, int max);

void	send_b_to_a(t_list **a, t_list **b);

/*
 - Sorting - Small
 */

void	sort_three(t_list **a);

void	sort_five(t_list **a, t_list **b, int size);

/*
 - Sorting - General
 */

bool	check_sorted(t_list *a);

void	sort(t_list **a, t_list **b);

/* 
 - Macros - Print status
 */

# define PRINT true
# define NO_PRINT false

/* 
 - Macros - Exit / error codes
 */

/** Error: Invalid argument count. No numbers to sort were provided. */
# define ERR_ARGC 1

/** Error: Program input is not numeric. */
# define ERR_INPUT_NOT_NUMERIC 2

/** Error: Malloc failed. */
# define ERR_MALLOC 3

/** Error: Provided input is already sorted. */
# define ERR_ALREADY_SORTED 4

/** Error: Input contains duplicate numbers */
# define ERR_DUPLICATES 5

#endif
