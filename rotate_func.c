/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:08:20 by danimart          #+#    #+#             */
/*   Updated: 2022/01/19 17:41:08 by danimart         ###   ########.fr       */
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
		tmp = ft_lstnew((*a)->next->content);
		tmp->next = (*a)->next->next;
		(*a)->next = NULL;
		ft_lstadd_back(&tmp, *a);
		*a = tmp;
	}
}

void	rotate_b(t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		write(1, "rb\n", 4);
	if (*b && (*b)->next)
	{
		tmp = ft_lstnew((*b)->next->content);
		tmp->next = (*b)->next->next;
		(*b)->next = NULL;
		ft_lstadd_back(&tmp, *b);
		*b = tmp;
	}
}

void	rotate_ab(t_list **a, t_list **b)
{
	write(1, "rr\n", 4);
	rotate_a(a, 0);
	rotate_b(b, 0);
}
