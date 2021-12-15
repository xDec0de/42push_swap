/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debugger.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:53:32 by danimart          #+#    #+#             */
/*   Updated: 2021/12/15 13:02:29 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	test_swap(t_list *a, t_list *b)
{
	print_stacks(a, b);
	swap_a(a, 1);
	print_stacks(a, b);
	swap_a(a, 1);
	print_stacks(a, b);
}

void	test_push(t_list *a, t_list *b)
{
	print_stacks(a, b);
	push_b(&a, &b);
	print_stacks(a, b);
	push_b(&a, &b);
	print_stacks(a, b);
	push_b(&a, &b);
	print_stacks(a, b);
	push_b(&a, &b);
	print_stacks(a, b);
	push_a(&a, &b);
	print_stacks(a, b);
	push_a(&a, &b);
	print_stacks(a, b);
	push_a(&a, &b);
	print_stacks(a, b);
	push_a(&a, &b);
	print_stacks(a, b);
}