/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:36:24 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/10 00:45:47 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_a(t_list *init)
{
	static t_list *a = NULL;

	if (init != NULL)
		a = init;
	return (a);
}

t_list	*get_b(t_list *init)
{
	static t_list *b = NULL;

	if (init != NULL)
		b = init;
	return (b);
}

t_list	*init_stack_element(t_list *next)
{
	t_list	*stack;

	stack = ps_malloc(sizeof(t_list));
	stack->content = 0;
	stack->modified = false;
	stack->next = next;
	return (stack);
}

void	free_stacks(t_list *a, t_list*b)
{
	t_list	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
	a = NULL;
	tmp = b;
	while (tmp != NULL)
	{
		tmp = b->next;
		free(b);
		b = tmp;
	}
	b = NULL;
}

void	exit_ps(t_list *a, t_list *b, int exit_code)
{
	if (exit_code != EXIT_SUCCESS && exit_code != ERR_ARGC
		&& exit_code != ERR_ALREADY_SORTED)
		write(STDOUT_FILENO, "Error\n", 6);
	free_stacks(a, b);
	exit(exit_code);
}
