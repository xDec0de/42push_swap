/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:47:18 by danimart          #+#    #+#             */
/*   Updated: 2025/03/10 14:22:52 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_list	*ft_lstmin_unmod(t_list *lst)
{
	t_list	*min;

	if (!lst)
		return (NULL);
	min = NULL;
	while (lst != NULL)
	{
		if (min == NULL && lst->modified == 1)
		{
			lst = lst->next;
			continue ;
		}
		else if (min == NULL)
			min = lst;
		else if ((min->content > lst->content) && lst->modified == 0)
			min = lst;
		lst = lst->next;
	}
	if (min->modified == 1)
		return (NULL);
	return (min);
}
