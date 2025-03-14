/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:42:56 by danimart          #+#    #+#             */
/*   Updated: 2025/03/13 16:34:01 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap_a(t_list **a, bool print)
{
	int	first;

	if (print)
		write(1, "sa\n", 3);
	if (*a && (*a)->next)
	{
		first = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = first;
	}
	return (1);
}

int	swap_b(t_list **b, bool print)
{
	int	first;

	if (print)
		write(1, "sb\n", 3);
	if (*b && (*b)->next)
	{
		first = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = first;
	}
	return (1);
}

int	swap_ab(t_list **a, t_list **b)
{
	write(1, "ss\n", 3);
	swap_a(a, NO_PRINT);
	swap_b(b, NO_PRINT);
	return (1);
}
