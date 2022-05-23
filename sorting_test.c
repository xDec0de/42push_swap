/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:29:49 by danimart          #+#    #+#             */
/*   Updated: 2022/05/23 18:05:28 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	lowest_a_to_b(t_list **a, t_list **b)
{
	int	lowpos;
	int	asize;
	int	i;

	lowpos = get_low_pos(a);
	asize = ft_lstsize(*a);
	if (lowpos == 2)
		swap_a(a, 1);
	else if (lowpos > (asize / 2))
		while (lowpos <= asize--)
			rev_rotate_a(a, 1);
	else
	{
		i = 1;
		while (lowpos > i++)
			rotate_a(a, 1);
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

void	simplify_stack(t_list **a, t_list **b, int size)
{
	int		i;
	t_list	*to_modify;

	i = 0;
	while (i < size)
	{
		to_modify = ft_lstmin_unmod(*a);
		if (to_modify == NULL)
			break;
		to_modify->content = i;
		to_modify->modified = 1;
		i++;
	}
	print_stacks(*a, *b);
}

void	sort_all(t_list **a, t_list **b, int size)
{
	simplify_stack(a, b, size);
	/*while(size > 3)
	{
		if (check_sorted(*a))
			break;
		lowest_a_to_b(a, b);
		size--;
	}
	if (size == 3)
		sort_three(a);
	while (*b)
		push_a(a, b);*/
}
