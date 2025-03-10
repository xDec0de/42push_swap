/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 21:51:31 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/10 00:45:09 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ps_malloc(int size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		exit_ps(get_a(NULL), get_b(NULL), ERR_MALLOC);
	return (result);
}
