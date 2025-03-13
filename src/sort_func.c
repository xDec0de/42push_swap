/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:29:49 by danimart          #+#    #+#             */
/*   Updated: 2025/03/13 16:38:18 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sorted(t_list *a)
{
	int	last;

	while (a->next != NULL)
	{
		last = a->content;
		if (a->next->content < last)
			return (false);
		a = a->next;
	}
	return (true);
}

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

void	sort_all(t_list **a, t_list **b, int size)
{
	int	div_size;
	int	range_min;

	simplify_stack(a, size);
	div_size = get_div_size(size);
	range_min = 0;
	while (range_min < size)
	{
		send_b_easiest(a, b, range_min, range_min + div_size);
		range_min += div_size;
	}
	send_b_to_a(a, b);
}

void	sort(t_list **a, t_list **b)
{
	int	size;

	size = ps_lstsize(*a);
	if (size == 2)
		swap_a(a, PRINT);
	if (size == 3)
		sort_three(a);
	if (size == 5 || size == 4)
		sort_five(a, b, size);
	if (size > 5)
		sort_all(a, b, size);
}
