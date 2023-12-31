/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_operator_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:54:03 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 06:33:21 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

void	ra(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	write(1, "ra\n", 3);
}

void	rb(t_stack *a, t_stack *b)
{
	rotate_b(a, b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate_r(a, b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *a, t_stack *b)
{
	rev_rotate_a(a, b);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *a, t_stack *b)
{
	rev_rotate_b(a, b);
	write(1, "rrb\n", 4);
}
