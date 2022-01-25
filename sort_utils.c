/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:52 by danimart          #+#    #+#             */
/*   Updated: 2022/01/25 19:58:50 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_b(int lowpos, t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*a);
	if (lowpos > i / 2)
		while (lowpos <= i--)
			rev_rotate_a(a, 1);
	else
	{
		i = 1;
		while (lowpos > i++)
			rotate_a(a, 1);
	}
	push_b(a, b);
}

void	send_a(int lowpos, t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(*b);
	if (lowpos > i / 2)
		while (lowpos <= i--)
			rev_rotate_b(b, 1);
	else
	{
		i = 1;
		while (lowpos > i++)
			rotate_b(b, 1);
	}
	push_a(a, b);
}

void	send_lowest(t_list **from, t_list **to, char stack)
{
	t_list	*tmp;
	int		i;
	int		lowpos;
	int		lowest;

	i = 1;
	tmp = *from;
	lowpos = 1;
	lowest = tmp->content;
	while (tmp)
	{
		if (lowest > tmp->content)
		{
			lowpos = i;
			lowest = tmp->content;
		}
		tmp = tmp->next;
		i++;
	}
	if (stack == 'b')
		send_b(lowpos, from, to);
	else
		send_a(lowpos, from, to);
}
