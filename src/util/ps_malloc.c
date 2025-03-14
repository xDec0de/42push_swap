/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:51:31 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/10 10:04:20 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ps_malloc(int size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		ps_exit(get_a(NULL), get_b(NULL), ERR_MALLOC);
	return (result);
}
