/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:24:44 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 16:32:11 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_div_size(int size)
{
	if (size <= 25)
		return (5);
	else if (size <= 50)
		return (10);
	else if (size <= 100)
		return (20);
	else
		return (40);
}

void	full_sort(t_list **a, t_list **b, int size)
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
