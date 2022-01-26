/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:29:49 by danimart          #+#    #+#             */
/*   Updated: 2022/01/26 20:21:53 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_sort(t_list **a, t_list **b, int size)
{
	if (size == 2)
		swap_a(a, 1);
	if (size == 3)
		sort_three(a);
	if (size == 5 || size == 4)
		sort_five(a, b, size);
	if(size > 5)
		sort_all(a, b, size);
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
	else if(f > t)
		rev_rotate_a(a, 1);
}

void	sort_five(t_list **a, t_list **b, int size)
{
	if (size == 5)
		send_lowest(a, b, 'b');
	send_lowest(a, b, 'b');
	sort_three(a);
	if (size == 5)
		push_a(a, b);
	push_a(a, b);
}

void	sort_all(t_list **a, t_list **b, int size)
{
	while(size > 3)
	{
		send_lowest(a, b, 'b');
		size--;
	}
	sort_three(a);
	while (*b)
		push_a(a, b);
}
