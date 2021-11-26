/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:05:02 by danimart          #+#    #+#             */
/*   Updated: 2021/11/26 15:42:52 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int code)
{
	if (code == 2)
		write(1, "\e[1;31mError\e[1;30m: \e[0;31mInsuficient arguments.\n\e[0m", 52);
	else if (code == 3)
		write(1, "\e[1;31mError\e[1;30m: \e[0;31mInput is\
 already sorted.\n\e[0m", 58);
	else if (code == 4)
		write(1, "\e[1;31mError\e[1;30m: \e[0;31mInput is not numeric.\n\e[0m", 55);
	else if (code == 5)
		write(1, "\e[1;31mError\e[1;30m: \e[0;31mInteger overflow.\n\e[0m", 55);
	else if (code != 0)
		write(1, "\e[1;31mError\e[1;30m: \e[0;31mUnknown.\n\e[0m", 42);
	exit(code);
}

void	check_numeric(int argc, char **a)
{
	int		i;
	int		j;
	int		has_digit;

	i = 1;
	j = 0;
	while (i <= argc)
	{
		has_digit = 0;
		j = 0;
		while (a[i][j])
		{
			if (ft_isdigit(a[i][j]))
				has_digit = 1;
			if ((a[i][j] == '-' || a[i][j] == '+') && !ft_isdigit(a[i][j + 1]))
				error(4);
			else if (!ft_isdigit(a[i][j]) && a[i][j] != ' '
				&& a[i][j] == '-' && a[i][j] == '+')
				error(4);
			j++;
		}
		if (!has_digit)
			error(4);
		i++;
	}
}

int	to_stack_send(long *res, char *sign, t_list *a)
{
	long	r;

	r = *res;
	if (*sign == '-')
		r *= -1;
	*res = 0;
	if ((*sign == '-' && r < -2147483648) || (*sign == '+' && r > 2147483647))
		error(5);
	*sign = '+';
	printf("%ld\n", r);
	a = NULL;
	return (0);
}

void	to_stack_check(const char *str, t_list *a)
{
	int		i;
	long	res;
	char	sign;
	int		modified;

	i = 0;
	res = 0;
	modified = 0;
	sign = '+';
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
		|| str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' || str[i] == '+')
			sign = str[i++];
		if (str[i] != ' ' && str[i] != '-' && str[i] != '+')
		{
			res = (res * 10) + (str[i] - '0');
			modified = 1;
		}
		else if (!str[i] || (str[i] == ' ' && str[i] != ' '))
			modified = to_stack_send(&res, &sign, a);
		i++;
	}
	modified = to_stack_send(&res, &sign, a);
}

int	main(int argc, char **args)
{
	t_list	*a;
	int		i;

	i = 1;
	argc--;
	if (argc <= 1 || !args)
		error(2);
	check_numeric(argc, args);
	a = NULL;
	while (i <= argc)
		to_stack_check(args[i++], a);
	return (0);
}
