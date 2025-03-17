/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:19:10 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 16:49:29 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->content;
	s = (*a)->next->content;
	t = (*a)->next->next->content;
	if (f > s && s < t && f < t)
		swap_a(a, PRINT);
	else if (f > s && s > t && t < f)
	{
		swap_a(a, PRINT);
		rev_rotate_a(a, PRINT);
	}
	else if (f > s && s < t && f > t)
		rotate_a(a, PRINT);
	else if (f < s && s > t && t > f)
	{
		swap_a(a, PRINT);
		rotate_a(a, PRINT);
	}
	else if (f > t)
		rev_rotate_a(a, PRINT);
}

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

void	lowest_a_to_b(t_list **a, t_list **b)
{
	int	lowpos;
	int	asize;
	int	i;

	lowpos = get_low_pos(a);
	asize = ps_lstsize(*a);
	if (lowpos == 2)
		swap_a(a, PRINT);
	else if (lowpos > (asize / 2))
		while (lowpos <= asize--)
			rev_rotate_a(a, PRINT);
	else
	{
		i = 1;
		while (lowpos > i++)
			rotate_a(a, PRINT);
	}
	push_b(a, b);
}

void	sort_five(t_list **a, t_list **b, int size)
{
	if (size == 5)
		lowest_a_to_b(a, b);
	lowest_a_to_b(a, b);
	sort_three(a);
	if (size == 5)
		push_a(a, b);
	push_a(a, b);
}
