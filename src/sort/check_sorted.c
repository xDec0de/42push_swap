/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:26:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 16:35:55 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	check_sorted(t_list *a)
{
	int	last;

	while (a->next != NULL)
	{
		last = a->content;
		if (a->next->content < last)
			return (false);
		a = a->next;
	}
	return (true);
}
