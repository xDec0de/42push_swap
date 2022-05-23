/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:17:25 by danimart          #+#    #+#             */
/*   Updated: 2022/05/05 09:27:01 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	write(1, "pa\n", 3);
	if (*b)
	{
		tmp = ft_lstnew((*b)->content);
		tmp->next = *a;
		*a = tmp;
		tmp = (*b)->next;
		free(*b);
		*b = tmp;
	}
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	write(1, "pb\n", 3);
	if (*a)
	{
		tmp = ft_lstnew((*a)->content);
		tmp->next = *b;
		*b = tmp;
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
