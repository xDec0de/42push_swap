/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:33:54 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 16:41:02 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
	while (lst != NULL)
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

	pos = get_pos(*a, value);
	if (pos > (size / 2))
		while (pos < size)
			pos += rev_rotate_a(a, PRINT);
	else
		while (pos > 0)
			pos -= rotate_a(a, PRINT);
	push_b(a, b);
	if (ps_lstsize(*b) < 10)
		return ;
	if (ps_lstlast(*b)->content < (*b)->content)
		rotate_b(b, PRINT);
}

void	send_b_easiest(t_list **a, t_list **b, int min, int max)
{
	int			easiest;

	easiest = get_easiest(*a, min, max, ps_lstsize(*a));
	while (easiest != -1)
	{
		send_value_to_b(a, b, easiest, ps_lstsize(*a));
		easiest = get_easiest(*a, min, max, ps_lstsize(*a));
	}
}
