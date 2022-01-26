/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:05:02 by danimart          #+#    #+#             */
/*   Updated: 2022/01/26 19:28:08 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int code)
{
	if (code != 2 && code != 3)
		write (1, "Error\n", 6);
	exit(code);
}

void	free_stacks(t_list **a, t_list**b)
{
	struct s_list	*list;

	if (!a)
		return ;
	list = *a;
	while (list)
	{
		free(list);
		list = list->next;
	}
	*a = NULL;
	if (!b)
		return ;
	list = *b;
	while (list)
	{
		free(list);
		list = list->next;
	}
	*b = NULL;
}

int	to_stack_send(long *res, char *sign, t_list **a)
{
	long	r;

	r = *res;
	if (*sign == '-')
		r *= -1;
	*res = 0;
	if ((*sign == '-' && r < -2147483648) || (*sign == '+' && r > 2147483647))
		error(5);
	*sign = '+';
	if (a == NULL)
		*a = ft_lstnew(r);
	else
		ft_lstadd_back(a, ft_lstnew(r));
	return (0);
}

void	leaks(void)
{
	printf("\n\e[1;31mLeak report\e[1;30m:\n\e[0;36m\n");
	system("leaks push_swap | grep leaked");
	printf("\e[0m\n");
}

int	main(int argc, char **args)
{
	t_list	*a;
	t_list	*b;
	int		i;

	i = 1;
	argc--;
	a = NULL;
	b = NULL;
	//atexit(leaks);
	if (argc < 1 || !args)
		error(2);
	check_numeric(argc, args);
	while (i <= argc)
		to_stack_check(args[i++], &a);
	if (check_sorted(a))
		error(3);
	test_sort(&a, &b, check_duplicates(a));
	//print_stacks(a, b);
	free_stacks(&a, &b);
	return (0);
}
