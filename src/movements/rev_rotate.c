/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:02:26 by danimart          #+#    #+#             */
/*   Updated: 2025/03/17 16:10:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rev_rotate_a(t_list **a, bool print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		write(1, "rra\n", 4);
	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = *a;
		last = ps_lstlast(*a);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *a;
		*a = last;
	}
	return (1);
}

int	rev_rotate_b(t_list **b, bool print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		write(1, "rrb\n", 4);
	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = *b;
		last = ps_lstlast(*b);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *b;
		*b = last;
	}
	return (1);
}

int	rev_rotate_ab(t_list **a, t_list **b)
{
	write(1, "rrr\n", 4);
	rev_rotate_a(a, NO_PRINT);
	rev_rotate_b(b, NO_PRINT);
	return (1);
}
