/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:05:02 by danimart          #+#    #+#             */
/*   Updated: 2022/01/11 15:51:56 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int code)
{
	if (EXTENDED_ERROR)
	{
		if (code == 1)
			write(1, "\e[1;31mError\e[1;30m: \e[0;31mDuplicated numbers.\
			\n\e[0m", 57);
		else if (code == 2)
			write(1, "\e[1;31mError\e[1;30m: \e[0;31mInsuficient arguments.\
			\n\e[0m", 60);
		else if (code == 3)
			write(1, "\e[1;31mError\e[1;30m: \e[0;31mInput is already sorted.\
			\n\e[0m", 65);
		else if (code == 4)
			write(1, "\e[1;31mError\e[1;30m: \e[0;31mInput is not numeric.\
			\n\e[0m", 62);
		else if (code == 5)
			write(1, "\e[1;31mError\e[1;30m: \e[0;31mInteger overflow.\n\e[0m", 55);
		else if (code != 0)
			write(1, "\e[1;31mError\e[1;30m: \e[0;31mUnknown.\n\e[0m", 46);
	}
	else
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
	if ((*sign == '-' && r < -2147483648) || (*sign == '+' && r > 2147483647))
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

	i = 1;
	argc--;
	a = NULL;
	b = NULL;
	if (argc < 1 || !args)
		error(2);
	check_numeric(argc, args);
	while (i <= argc)
		to_stack_check(args[i++], &a);
	if (check_sorted(a))
		error(3);
	check_duplicates(a);
	return (0);
}
