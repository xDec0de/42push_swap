/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:57:06 by danimart          #+#    #+#             */
/*   Updated: 2022/01/10 15:21:22 by danimart         ###   ########.fr       */
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
		else if (!str[i] || (str[i] == ' ' && str[i + 1] != ' '))
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
			if (!ft_isdigit(a[i][j]) && a[i][j] != '-' && a[i][j] != '+' && a[i][j] != ' ')
				error(4);
			if (ft_isdigit(a[i][j]))
				has_digit = 1;
			if ((a[i][j] == '-' || a[i][j] == '+') && !ft_isdigit(a[i][j + 1]))
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

void	check_duplicates(t_list *a)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		*list;

	i = ft_lstsize(a);
	if(i <= 1)
		error(2);
	list = ft_calloc(i, sizeof(int));
	tmp = a;
	i = 0;
	while (tmp)
	{
		j = 0;
		list[i] = tmp->content;
		while (j <= i)
		{
			if (list[j] == tmp->content && j != i)
				error(1);
			j++;
		}
		i++;
		tmp = tmp->next;
	}
}

/*void	check_duplicates(t_list *a)
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
}*/