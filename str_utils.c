/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:52:14 by danimart          #+#    #+#             */
/*   Updated: 2021/12/16 16:52:47 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void	*str, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
		((unsigned char *) str)[i++] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
