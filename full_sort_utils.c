/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:40:30 by danimart          #+#    #+#             */
/*   Updated: 2022/05/25 18:08:30 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_easiest(t_list *lst, int min, int max, int size)
{
	int	difficulty;
	int	last_dif;
	int	i;
	int	res;

	res = -1;
	i = 0;
	difficulty = 0;
	last_dif = -1;
	while (lst)
	{
		if (i > (size / 2))
			difficulty--;
		else
			difficulty++;
		if (lst->content >= min && lst->content <= max \
			&& (last_dif == -1 || difficulty < last_dif))
		{
			res = lst->content;
			last_dif = difficulty;
		}
		i++;
		lst = lst->next;
	}
	return (res);
}

void	send_value_to_b(t_list **a, t_list **b, int value, int size)
{
	int		pos;
	t_list	*tmp;

	tmp = *a;
	pos = 0;
	while (tmp->content != value)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos > (size / 2))
	{
		while (pos < size)
			pos += rev_rotate_a(a, 1);
		push_b(a, b);
	}
	else
	{
		while (pos > 0)
			pos -= rotate_a(a, 1);
		push_b(a, b);
	}
}

void	send_b_easiest(t_list **a, t_list **b, int min, int max)
{
	int	easiest;

	easiest = get_easiest(*a, min, max, ft_lstsize(*a));
	while (easiest != -1)
	{
		send_value_to_b(a, b, easiest, ft_lstsize(*a));
		easiest = get_easiest(*a, min, max, ft_lstsize(*a));
	}
}

void	send_value_to_a(t_list **a, t_list **b, int value, int size)
{
	int		pos;
	t_list	*tmp;

	tmp = *b;
	pos = 0;
	while (tmp->content != value)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos > (size / 2))
	{
		while (pos < size)
			pos += rev_rotate_b(b, 1);
		push_a(a, b);
	}
	else
	{
		while (pos > 0)
			pos -= rotate_b(b, 1);
		push_a(a, b);
	}
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
		send_value_to_a(a, b, highest, ft_lstsize(*b));
		send_b_to_a(a, b);
	}
}
