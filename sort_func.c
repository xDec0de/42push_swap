/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:29:49 by danimart          #+#    #+#             */
/*   Updated: 2022/05/25 17:48:14 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->content;
	s = (*a)->next->content;
	t = (*a)->next->next->content;
	if (f > s && s < t && f < t)
		swap_a(a, 1);
	else if (f > s && s > t && t < f)
	{
		swap_a(a, 1);
		rev_rotate_a(a, 1);
	}
	else if (f > s && s < t && f > t)
		rotate_a(a, 1);
	else if (f < s && s > t && t > f)
	{
		swap_a(a, 1);
		rotate_a(a, 1);
	}
	else if (f > t)
		rev_rotate_a(a, 1);
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
		printf("Seding values to b from %d to %d\n", range_min, range_min+div_size);
		send_b_easiest(a, b, range_min, range_min+div_size);
		range_min += div_size;
	}
}

void	sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
		swap_a(a, 1);
	if (size == 3)
		sort_three(a);
	if (size == 5 || size == 4)
		sort_five(a, b, size);
	if (size > 5)
		sort_all(a, b, size);
}
