/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debugger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:53:32 by danimart          #+#    #+#             */
/*   Updated: 2022/05/25 17:28:47 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Prints stack a and b*/
void	print_stacks(t_list *a, t_list *b)
{
	printf("\e\e[1;30m-----------------\n\e[0;31mStacks:\n\n\e[0m");
	while (a || b)
	{
		if (a)
		{
			printf("\e[0;32m%d\e[0m", (int)a->content);
			a = a->next;
		}
		else
			printf("\e[0;30m0\e[0m");
		printf(" ");
		if (b)
		{
			printf("\e[0;36m%d\e[0m", (int)b->content);
			b = b->next;
		}
		else
			printf("\e[0;30m0\e[0m");
		printf("\n");
	}
	printf("\e[0;32m- \e[0;36m-\n\e[0;32ma \e[0;36mb\n\e[1;30m-----------------\n\e[0m");
}

void	debug_duplicates(t_list *a)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		*list;

	i = 0;
	list = ft_calloc(ft_lstsize(a), sizeof(int));
	tmp = a;
	printf("\e\e[1;30m-----------------------\n\e[0;31mDuplicate finder:\n\e[0m");
	while (tmp)
	{
		j = 0;
		printf("\e[1;30m\nIteration: \e[0;31m%d\n\e[0m", i);
		list[i] = tmp->content;
		while (j <= i)
		{
			if (list[j] == tmp->content && j != i)
				printf("\e[1;31mD: %d\n\e[0m", list[j]);
			else if (j != i)
				printf("\e[0mN: %d\n", list[j]);
			else
				printf("\e[0;32mC: %d\n\e[0m", list[j]);
			j++;
		}
		i++;
		tmp = tmp->next;
	}
	printf("\e[1;30m-----------------------\n\e[0m");
}
