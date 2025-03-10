/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:05:02 by danimart          #+#    #+#             */
/*   Updated: 2025/03/10 10:05:30 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int code)
{
	if (code != 2 && code != 3)
		write (1, "Error\n", 6);
	exit(code);
}

int	to_stack_send(long *res, char *sign, t_list **a)
{
	long	r;

	r = *res;
	if (*sign == '-')
		r *= -1;
	*res = 0;
	if ((*sign == '-' && r < INT_MIN) || (*sign == '+' && r > INT_MAX))
		error(5);
	*sign = '+';
	if (a == NULL)
		*a = ft_lstnew(r);
	else
		ft_lstadd_back(a, ft_lstnew(r));
	return (0);
}

int	main(int argc, char **args)
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc < 2)
		exit(ERR_ARGC);
	check_numeric(argc, args);
	i = 1;
	while (i < argc)
	{
		to_stack_check(args[i], &a);
		i++;
	}
	if (check_sorted(a))
		ps_exit(a, b, ERR_ALREADY_SORTED);
	sort(&a, &b, check_duplicates(a));
	ps_exit(a, b, EXIT_SUCCESS);
}
