/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_operator_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:52:30 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 06:33:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

void	sa(t_stack *a, t_stack *b)
{
	swap_a(a, b);
	write(1, "sa\n", 3);
}

void	sb(t_stack *a, t_stack *b)
{
	swap_b(a, b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_s(a, b);
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	push_a(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push_b(a, b);
	write(1, "pb\n", 3);
}
