/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:06:27 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 16:10:11 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ps_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ps_lstlast(*lst)->next = new;
}
