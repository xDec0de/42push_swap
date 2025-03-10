/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_provider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:49:50 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/10 09:51:11 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_a(t_list *init)
{
	static t_list	*a = NULL;

	if (init != NULL)
		a = init;
	return (a);
}

t_list	*get_b(t_list *init)
{
	static t_list	*b = NULL;

	if (init != NULL)
		b = init;
	return (b);
}
