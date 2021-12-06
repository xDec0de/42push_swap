/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:58:09 by danimart          #+#    #+#             */
/*   Updated: 2021/09/23 10:12:51 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
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
	return (list);
}
