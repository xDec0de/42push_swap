/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:47:18 by danimart          #+#    #+#             */
/*   Updated: 2022/01/11 13:09:39 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int				i;
	struct s_list	*list;

	i = 1;
	if (!lst)
		return (0);
	list = lst;
	while (list->next != NULL)
	{
		list = list->next;
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
	struct s_list	*list;

	if (!lst)
		return (NULL);
	list = lst;
	while (list->next != NULL)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	struct s_list	*list;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
}
