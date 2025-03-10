/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:51:54 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/10 09:52:18 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ps_exit(t_list *a, t_list *b, int exit_code)
{
	if (exit_code != EXIT_SUCCESS && exit_code != ERR_ARGC
		&& exit_code != ERR_ALREADY_SORTED)
		write(STDOUT_FILENO, "Error\n", 6);
	free_stacks(a, b);
	exit(exit_code);
}

