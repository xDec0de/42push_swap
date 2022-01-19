/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:29:49 by danimart          #+#    #+#             */
/*   Updated: 2022/01/19 18:11:34 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_sort(t_list **a, t_list **b, int size)
{
	*b = *b;
	if (size == 2)
		swap_a(a, 1);
	if (size == 3)
		sort_three(a);
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
	else
		rev_rotate_a(a, 1);
}
