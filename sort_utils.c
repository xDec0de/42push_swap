/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:12:52 by danimart          #+#    #+#             */
/*   Updated: 2022/05/25 17:48:22 by danimart         ###   ########.fr       */
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

void	simplify_stack(t_list **a, int size)
{
	int		i;
	t_list	*to_modify;

	i = 0;
	while (i < size)
	{
		to_modify = ft_lstmin_unmod(*a);
		if (to_modify == NULL)
			break ;
		to_modify->content = i;
		to_modify->modified = 1;
		i++;
	}
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
