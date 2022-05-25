/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:52 by danimart          #+#    #+#             */
/*   Updated: 2022/05/25 17:22:12 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_div_size(int size)
{
	if (size <= 25)
		return (5);
	else if (size <= 50)
		return (10);
	else if (size <= 100)
		return (20);
	else
		return (50);
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

void	send_b_easiest(t_list **a, t_list **b, int min, int max)
{
	int	easiest;

	easiest = get_easiest(*a, min, max, ft_lstsize(*a));
	while (easiest != -1)
	{
		send_value_to_b(a, b, easiest, ft_lstsize(*a));
		easiest = get_easiest(*a, min, max, ft_lstsize(*a));
	}
	print_stacks(*a, *b);
}
