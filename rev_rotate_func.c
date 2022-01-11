/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:02:26 by danimart          #+#    #+#             */
/*   Updated: 2022/01/11 16:16:17 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **a, int print)
{
	t_list	*tmp;

	if (print)
		write(1, "rra\n", 4);
	if (*a && (*a)->next)
	{
		tmp = ft_lstnew(ft_lstlast(*a)->content);
		while ((*a)->next != NULL)
		{
			ft_lstadd_back(&tmp, ft_lstnew((*a)->content));
			(*a) = (*a)->next;
		}
		*a = tmp;
	}
}

void	rev_rotate_b(t_list **b, int print)
{
	t_list	*tmp;

	if (print)
		write(1, "rrb\n", 4);
	if (*b && (*b)->next)
	{
		tmp = ft_lstnew(ft_lstlast(*b)->content);
		while ((*b)->next != NULL)
		{
			ft_lstadd_back(&tmp, ft_lstnew((*b)->content));
			(*b) = (*b)->next;
		}
		*b = tmp;
	}
}

void	rev_rotate_ab(t_list *a, t_list *b)
{
	write(1, "rrr\n", 4);
	rev_rotate_a(&a, 0);
	rev_rotate_b(&b, 0);
}
