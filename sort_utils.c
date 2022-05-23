/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:52 by danimart          #+#    #+#             */
/*   Updated: 2022/05/19 13:52:29 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	get_low_pos(t_list	**stack)
{
	t_list	*tmp;
	int		i;
	int		lowpos;
	int		lowest;

	i = 1;
	tmp = *stack;
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
	return (lowpos);
}

void	send_b(t_list **a, t_list **b)
{
	int	i;
	int	lowpos;

	lowpos = get_low_pos(b);
	i = ft_lstsize(*a);
	if (lowpos == 2)
		swap_b(b, 1);
	else if (lowpos > i / 2)
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
*/

/*int	get_low_pos(t_list	**stack)
{
	t_list	*tmp;
	int		i;
	int		lowpos;
	int		lowest;

	i = 1;
	tmp = *stack;
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
	return (lowpos);
}

void	send_b(t_list **a, t_list **b)
{
	int	i;
	int	lowpos_a;

	lowpos_a = get_low_pos(a);
	i = ft_lstsize(*a);
	if (lowpos_a > i / 2)
		while (lowpos_a <= i--)
			rev_rotate_a(a, 1);
	else
	{
		i = 1;
		while (lowpos_a > i++)
			rotate_a(a, 1);
	}
	push_b(a, b);
}

void	send_a(t_list **a, t_list **b)
{
	int	i;
	int	lowpos_a;

	lowpos_a = get_low_pos(a);
	i = ft_lstsize(*b);
	if (lowpos_a > i / 2)
		while (lowpos_a <= i--)
			rev_rotate_b(b, 1);
	else
	{
		i = 1;
		while (lowpos_a > i++)
			rotate_b(b, 1);
	}
	push_a(a, b);
}

void	send_lowest(t_list **from, t_list **to, char stack)
{
	if (stack == 'b')
		send_b(from, to);
	else
		send_a(from, to);
}
*/