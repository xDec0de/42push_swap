/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:57:06 by danimart          #+#    #+#             */
/*   Updated: 2021/12/06 11:45:18 by danimart         ###   ########.fr       */
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
			printf("%c, %d\n", a[i][j], ft_isdigit(a[i][j]));
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

int	check_sorted(t_list *a)
{
	int	sorted;
	int	last;

	sorted = 0;
	while (a->next)
	{
		last = a->content;
		if (a->next->content > last)
			sorted = 1;
		else
			return (0);
		a = a->next;
	}
	return (sorted);
}
