/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:02:26 by danimart          #+#    #+#             */
/*   Updated: 2025/03/13 15:39:53 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rev_rotate_a(t_list **a, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		write(1, "rra\n", 4);
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
	return (1);
}

int	rev_rotate_b(t_list **b, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (print)
		write(1, "rrb\n", 4);
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
	return (1);
}

int	rev_rotate_ab(t_list **a, t_list **b)
{
	write(1, "rrr\n", 4);
	rev_rotate_a(a, 0);
	rev_rotate_b(b, 0);
	return (1);
}
