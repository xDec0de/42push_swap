/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:27:47 by danimart          #+#    #+#             */
/*   Updated: 2021/12/06 09:43:34 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
