/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:26:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 18:51:07 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	check_sorted(t_list *stack)
{
	int	last;

	while (stack->next != NULL)
	{
		last = stack->content;
		if (stack->next->content < last)
			return (false);
		stack = stack->next;
	}
	return (true);
}
