/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:47:18 by danimart          #+#    #+#             */
/*   Updated: 2022/01/25 16:26:20 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstnew(int content)
{
	struct s_list	*list;

	list = malloc(sizeof(content));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

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
	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	ft_lstcpy(t_list *origin, t_list **copy)
{
	if (origin != NULL)
	{
		if (*copy == NULL)
		{
			*copy = ft_lstnew(origin->content);
			(*copy)->next = origin->next;
		}
		else
		{
			(*copy)->next = origin->next;
			(*copy)->content = origin->content;
		}
	}
}
