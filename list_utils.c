/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:47:18 by danimart          #+#    #+#             */
/*   Updated: 2022/05/23 18:24:55 by danimart         ###   ########.fr       */
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
	list->modified = 0;
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

/*t_list	*ft_lstmin_unmod(t_list *lst)
{
	t_list	*min;

	if (!lst)
		return (NULL);
	min = NULL;
	while (lst->next != NULL)
	{
		if (min == NULL && lst->modified == 0)
		{
			min = ft_lstnew(lst->content);
			printf("Min is null and lst is not modified, min is now %d\n", min->content);
		}
		else if (min != NULL)
		{
			if (min->content > lst->content && lst->modified == 0)
			{
				min->next = lst->next;
				min->content = lst->content;
				printf("Min is not null, set min to %d\n", min->content);
			}
			printf("Min is not null, ignored %d > %d\n", lst->content, min->content);
		}
		lst = lst->next;
	}
	return (min);
}*/
