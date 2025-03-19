/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:37:14 by daniema3          #+#    #+#             */
/*   Updated: 2025/03/19 16:58:11 by daniema3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ps_atoi(const char *str)
{
	size_t				i;
	unsigned long long	res;
	bool				negative;

	i = 0;
	negative = false;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negative = true;
	while (str[i] != '\0')
	{
		if (!ps_isdigit(str[i]))
			return (LONG_MIN);
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (i == 0)
		return (LONG_MIN);
	if ((!negative && res > INT_MAX)
		|| (negative && res > ((long long) INT_MAX + 1)))
		return (LONG_MIN);
	if (negative)
		return (-res);
	return (res);
}

t_list	*arg_to_lst(char *arg)
{
	long long	content;

	content = ps_atoi(arg);
	if (content == LONG_MIN)
		ps_exit(get_a(NULL), NULL, ERR_INPUT_NOT_NUMERIC);
	return (ps_lstinit(content, NULL));
}

void	check_duplicates(t_list *a)
{
	t_list	*tmp;

	while (a != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (tmp->content == a->content)
				ps_exit(a, NULL, ERR_DUPLICATES);
			tmp = tmp->next;
		}
		a = a->next;
	}
}

t_list	*input_to_a(int argc, char **args)
{
	int			i;
	t_list		*a;
	t_list		*tmp;

	i = 1;
	a = get_a(arg_to_lst(args[i]));
	i++;
	tmp = a;
	while (i < argc)
	{
		tmp->next = arg_to_lst(args[i]);
		tmp = tmp->next;
		i++;
	}
	check_duplicates(a);
	if (check_sorted(a))
		ps_exit(a, NULL, ERR_ALREADY_SORTED);
	return (a);
}
