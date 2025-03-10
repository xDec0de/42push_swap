/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:53:39 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/10 09:58:12 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*ps_lst_init(int content, t_list *next)
{
	t_list	*stack;

	stack = ps_malloc(sizeof(t_list));
	stack->content = content;
	stack->modified = false;
	stack->next = next;
	return (stack);
}
