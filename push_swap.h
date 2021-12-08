/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danimart <danimart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:31 by danimart          #+#    #+#             */
/*   Updated: 2021/12/08 15:57:51 by danimart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXTENDED_ERROR 1

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h> // debug

void	to_stack_check(const char *str, t_list **a);
void	check_numeric(int argc, char **a);
int		check_sorted(t_list *a);
void	error(int code);
int		to_stack_send(long *res, char *sign, t_list **a);
void	check_duplicates(t_list *a);
void	swap_a(t_list *a, int print);
void	swap_b(t_list *b, int print);
void	swap_ab(t_list *a, t_list *b);

// debug //

void	print_stacks(t_list *a, t_list *b);
void	test_swaps(t_list *a, t_list *b);

#endif