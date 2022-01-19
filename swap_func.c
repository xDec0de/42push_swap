/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:42:56 by danimart          #+#    #+#             */
/*   Updated: 2022/01/19 17:38:01 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **a, int print)
{
	int	first;
	int	second;

	if (print)
		write(1, "sa\n", 4);
	if (*a && (*a)->next)
	{
		first = (*a)->content;
		second = (*a)->next->content;
		(*a)->content = second;
		(*a)->next->content = first;
	}
}

void	swap_b(t_list **b, int print)
{
	int	first;
	int	second;

	if (print)
		write(1, "sb\n", 4);
	if (*b && (*b)->next)
	{
		first = (*b)->content;
		second = (*b)->next->content;
		(*b)->content = second;
		(*b)->next->content = first;
	}
}

void	swap_ab(t_list **a, t_list **b)
{
	write(1, "ss\n", 4);
	swap_a(a, 0);
	swap_b(b, 0);
}
