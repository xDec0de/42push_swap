/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:02:26 by danimart          #+#    #+#             */
/*   Updated: 2022/01/19 17:40:27 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_list **a, int print)
{
	t_list	*tmp;
	t_list	*cpy;

	if (print)
		write(1, "rra\n", 4);
	cpy = *a;
	if (*a && (*a)->next)
	{
		tmp = ft_lstnew(ft_lstlast(*a)->content);
		while (cpy->next != NULL)
		{
			ft_lstadd_back(&tmp, ft_lstnew(cpy->content));
			cpy = cpy->next;
		}
		ft_lstcpy(tmp, a);
	}
}

void	rev_rotate_b(t_list **b, int print)
{
	t_list	*tmp;
	t_list	*cpy;

	if (print)
		write(1, "rra\n", 4);
	cpy = *b;
	if (*b && (*b)->next)
	{
		tmp = ft_lstnew(ft_lstlast(*b)->content);
		while (cpy->next != NULL)
		{
			ft_lstadd_back(&tmp, ft_lstnew(cpy->content));
			cpy = cpy->next;
		}
		ft_lstcpy(tmp, b);
	}
}

void	rev_rotate_ab(t_list **a, t_list **b)
{
	write(1, "rrr\n", 4);
	rev_rotate_a(a, 0);
	rev_rotate_b(b, 0);
}
