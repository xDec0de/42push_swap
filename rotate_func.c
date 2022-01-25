/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:08:20 by danimart          #+#    #+#             */
/*   Updated: 2022/01/25 17:31:19 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a, int print)
{
	t_list	*tmp;

	if (print)
		write(1, "ra\n", 4);
	if (*a && (*a)->next)
	{
		tmp = (*a);
		ft_lstadd_back(&tmp, *a);
		*a = (*a)->next;
		tmp->next = NULL;
	}
}

void	rotate_b(t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		write(1, "rb\n", 4);
	if (*b && (*b)->next)
	{
		tmp = (*b);
		ft_lstadd_back(&tmp, *b);
		*b = (*b)->next;
		tmp->next = NULL;
	}
}

void	rotate_ab(t_list **a, t_list **b)
{
	write(1, "rr\n", 4);
	rotate_a(a, 0);
	rotate_b(b, 0);
}
