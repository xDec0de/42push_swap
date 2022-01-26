/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:02:26 by danimart          #+#    #+#             */
/*   Updated: 2022/01/26 19:17:29 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **a, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		write(1, "rra\n", 5);
	if (*a && (*a)->next)
	{
		tmp = *a;
		last = ft_lstlast(*a);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *a;
		*a = last;
	}
}

void	rev_rotate_b(t_list **b, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		write(1, "rrb\n", 5);
	if (*b && (*b)->next)
	{
		tmp = *b;
		last = ft_lstlast(*b);
		while (tmp->next->next)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = *b;
		*b = last;
	}
}

void	rev_rotate_ab(t_list **a, t_list **b)
{
	write(1, "rrr\n", 5);
	rev_rotate_a(a, 0);
	rev_rotate_b(b, 0);
}
