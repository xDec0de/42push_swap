/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:08:20 by danimart          #+#    #+#             */
/*   Updated: 2025/03/17 16:11:05 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate_a(t_list **a, bool print)
{
	t_list	*tmp;

	if (print)
		write(1, "ra\n", 3);
	if (*a != NULL && (*a)->next != NULL)
	{
		tmp = (*a);
		ps_lstadd_back(&tmp, *a);
		*a = (*a)->next;
		tmp->next = NULL;
	}
	return (1);
}

int	rotate_b(t_list **b, bool print)
{
	t_list	*tmp;

	if (print)
		write(1, "rb\n", 3);
	if (*b != NULL && (*b)->next != NULL)
	{
		tmp = (*b);
		ps_lstadd_back(&tmp, *b);
		*b = (*b)->next;
		tmp->next = NULL;
	}
	return (1);
}

int	rotate_ab(t_list **a, t_list **b)
{
	write(1, "rr\n", 4);
	rotate_a(a, NO_PRINT);
	rotate_b(b, NO_PRINT);
	return (1);
}
