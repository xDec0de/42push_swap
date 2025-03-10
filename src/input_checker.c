/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:57:06 by danimart          #+#    #+#             */
/*   Updated: 2025/03/10 12:56:21 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_stack_check(const char *str, t_list **a)
{
	int		i;
	long	res;
	char	sign;
	int		modified;

	i = 0;
	res = 0;
	modified = 0;
	sign = '+';
	while (ps_isdigit(str[i]) || str[i] == ' '
		|| str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' || str[i] == '+')
			sign = str[i++];
		if (str[i] != ' ' && str[i] != '-' && str[i] != '+')
		{
			res = (res * 10) + (str[i] - '0');
			modified = 1;
		}
		else if (modified && (!str[i] || (str[i] == ' ' && str[i + 1] != ' ')))
			modified = to_stack_send(&res, &sign, a);
		i++;
	}
	if (modified)
		modified = to_stack_send(&res, &sign, a);
}

void	check_numeric(int argc, char **a)
{
	int		i;
	int		j;
	int		has_digit;

	i = 1;
	j = 0;
	while (i < argc)
	{
		has_digit = 0;
		j = 0;
		while (a[i][j])
		{
			if (!ps_isdigit(a[i][j]) && a[i][j] != '-' && a[i][j]
			!= '+' && a[i][j] != ' ')
				error(4);
			if (ps_isdigit(a[i][j]))
				has_digit = 1;
			if ((a[i][j] == '-' || a[i][j] == '+') && !ps_isdigit(a[i][j + 1]))
				error(4);
			j++;
		}
		if (!has_digit)
			error(4);
		i++;
	}
}
