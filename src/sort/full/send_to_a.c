/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:32:02 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 16:41:20 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	send_value_to_a(t_list **a, t_list **b, int value, int size)
{
	int		pos;

	pos = get_pos(*b, value);
	if (pos > (size / 2))
		while (pos < size)
			pos += rev_rotate_b(b, PRINT);
	else
		while (pos > 0)
			pos -= rotate_b(b, PRINT);
	push_a(a, b);
}

void	send_b_to_a(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		highest;

	tmp = *b;
	highest = -1;
	while (tmp)
	{
		if (tmp->content > highest)
			highest = tmp->content;
		tmp = tmp->next;
	}
	if (highest != -1)
	{
		send_value_to_a(a, b, highest, ps_lstsize(*b));
		send_b_to_a(a, b);
	}
}
