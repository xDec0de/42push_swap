/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:31 by danimart          #+#    #+#             */
/*   Updated: 2025/03/19 16:29:05 by daniema3         ###   ########.fr       */
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
 * "Error\\n" will be written on `STDERR_FILENO` if
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

/**
 * @brief The `pa` movement. Takes the first element of stack
 * `a` and puts it at the top of stack `b`. Does nothing
 * if `b` is empty.
 * 
 * @param a A pointer to stack a.
 * @param b A pointer to stack b.
 * 
 * @return Always 1.
 */
int		push_a(t_list **a, t_list **b);

/**
 * @brief The `pb` movement. Takes the first element of stack
 * `b` and puts it at the top of stack `a`. Does nothing
 * if `a` is empty.
 * 
 * @param a A pointer to stack a.
 * @param b A pointer to stack b.
 * 
 * @return Always 1.
 */
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

/**
 * @brief The `sa` movement. Swaps the first element of
 * stack `a` with the second element of said stack.
 * So the first and the second elements swap places.
 * Does nothing if the stack contains less than two elements.
 * 
 * @param a A pointer to stack a.
 * 
 * @param print Whether to print the movement or not.
 * 
 * @return Always 1.
 */
int		swap_a(t_list **a, bool print);

/**
 * @brief The `sb` movement. Swaps the first element of
 * stack `b` with the second element of said stack.
 * So the first and the second elements swap places.
 * Does nothing if the stack contains less than two elements.
 * 
 * @param b A pointer to stack b.
 * 
 * @param print Whether to print the movement or not.
 * 
 * @return Always 1.
 */
int		swap_b(t_list **b, bool print);

/**
 * @brief The `ss` movement. Executes both `swap_a` and `swap_b`.
 * Swaps the first and second elements of both stacks, so the
 * first and second element of each stack switch places.
 * Does nothing per stack if the stack contains less than two elements.
 * 
 * @param a A pointer to stack a.
 * @param a A pointer to stack a.
 * 
 * @param print Whether to print the movement or not.
 * 
 * @return Always 1.
 */
int		swap_ab(t_list **a, t_list **b);

/*
 - Utils
 */

/**
 * @brief Checks if the provided `char` is
 * considered a digit or not.
 * 
 * @param ch The `char` to check.
 * 
 * @return `true` if `ch` is within the range
 * of `char` '0' to '9', `false` otherwise.
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

/**
 * @brief Sorting functions for stacks with an amount
 * higher than 5. This function will use an actual sorting
 * algorithm to sort all numbers on stack `a`.
 * 
 * @param a A pointer to stack a
 * @param b A pointer to stack b.
 * @param size The size of stack `a`.
 */
void	full_sort(t_list **a, t_list **b, int size);

/**
 * @brief Get the position of a certain `value` on the
 * provided `stack`.
 * 
 * @param lst The stack to iterate.
 * @param value The value to search.
 * 
 * @return The position of the requested `value` on the
 * provided `stack`. -1 if the `value` isn't found.
 */
int		get_pos(t_list *lst, int value);

/**
 * @brief Simplifies the provided `stack` so numbers follow
 * an order. The highest number will be `size - 1`, while numbers
 * in between will be lower by 1 until 0 is reached. So a stack
 * of size 100 will contain numbers from 0 to 99, respecting
 * their original values in order.
 * 
 * For example, the stack [-10, 5, 99, 31, -6, 0] will be
 * simplified to [0, 3, 5, 4, 1, 2].
 * 
 * @param stack A pointer to the stack to simplify, generally stack a.
 * @param size The size of the stack to simplify.
 */
void	simplify_stack(t_list **stack, int size);

void	send_b_easiest(t_list **a, t_list **b, int min, int max);

void	send_b_to_a(t_list **a, t_list **b);

/*
 - Sorting - Small
 */

/**
 * @brief Specific function used to sort a stack of 3 numbers.
 * This function contains the most efficient instructions for
 * all possible combinations of 3 numbers.
 * 
 * @param a A pointer to stack a.
 */
void	sort_three(t_list **a);

/**
 * @brief Specific function used to sort a stack of 4 or 5
 * numbers.
 * 
 * @param a A pointer to stack a.
 */
void	sort_five(t_list **a, t_list **b, int size);

/*
 - Sorting - General
 */

/**
 * @brief Checks if a stack is sorted, generally stack a.
 * 
 * @param stack A pointer to the first element of the stack to check
 * 
 * @return `true` if the `stack` is sorted, `false` otherwise.
 */
bool	check_sorted(t_list *stack);

/**
 * @brief The main sorting function. This function will call any
 * fuctions that are best suited to sort the provided stacks.
 * 
 * @param a A pointer to stack a.
 * @param b A pointer to stack b.
 */
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
