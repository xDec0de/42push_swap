/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:41:38 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 19:13:18 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_pos(t_list *stack, int value)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->content == value)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}
