/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:17:25 by danimart          #+#    #+#             */
/*   Updated: 2022/01/11 14:34:46 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	write(1, "pa\n", 4);
	if (*b)
	{
		tmp = ft_lstnew((*b)->content);
		tmp->next = *a;
		*a = tmp;
		*b = (*b)->next;
	}
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	write(1, "pb\n", 4);
	if (*a)
	{
		tmp = ft_lstnew((*a)->content);
		tmp->next = *b;
		*b = tmp;
		*a = (*a)->next;
	}
}
