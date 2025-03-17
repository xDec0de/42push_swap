/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:36:54 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 16:37:10 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	simplify_stack(t_list **a, int size)
{
	int		i;
	t_list	*to_modify;

	i = 0;
	while (i < size)
	{
		to_modify = ps_lstmin_unmod(*a);
		if (to_modify == NULL)
			break ;
		to_modify->content = i;
		to_modify->modified = true;
		i++;
	}
}
