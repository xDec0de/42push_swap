/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:08:20 by danimart          #+#    #+#             */
/*   Updated: 2025/03/13 15:40:26 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate_a(t_list **a, int print)
{
	t_list	*tmp;

	if (print)
		write(1, "ra\n", 3);
	if (*a && (*a)->next)
	{
		tmp = (*a);
		ft_lstadd_back(&tmp, *a);
		*a = (*a)->next;
		tmp->next = NULL;
	}
	return (1);
}

int	rotate_b(t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		write(1, "rb\n", 3);
	if (*b && (*b)->next)
	{
		tmp = (*b);
		ft_lstadd_back(&tmp, *b);
		*b = (*b)->next;
		tmp->next = NULL;
	}
	return (1);
}

int	rotate_ab(t_list **a, t_list **b)
{
	write(1, "rr\n", 4);
	rotate_a(a, 0);
	rotate_b(b, 0);
	return (1);
}
