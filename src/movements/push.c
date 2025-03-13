/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:17:25 by danimart          #+#    #+#             */
/*   Updated: 2025/03/13 15:39:45 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	write(1, "pa\n", 3);
	if (*b)
	{
		tmp = ps_lstinit((*b)->content, NULL);
		tmp->next = *a;
		*a = tmp;
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
	return (1);
}

int	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	write(1, "pb\n", 3);
	if (*a)
	{
		tmp = ps_lstinit((*a)->content, NULL);
		tmp->next = *b;
		*b = tmp;
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	return (1);
}
