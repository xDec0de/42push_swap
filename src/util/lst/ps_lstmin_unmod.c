/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lstmin_unmod.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:07:35 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/17 16:08:02 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_list	*ps_lstmin_unmod(t_list *lst)
{
	t_list	*min;

	if (!lst)
		return (NULL);
	min = NULL;
	while (lst != NULL)
	{
		if (min == NULL && lst->modified)
		{
			lst = lst->next;
			continue ;
		}
		else if (min == NULL)
			min = lst;
		else if ((min->content > lst->content) && !lst->modified)
			min = lst;
		lst = lst->next;
	}
	if (min->modified)
		return (NULL);
	return (min);
}