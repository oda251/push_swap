/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:40:39 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 06:29:20 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

void	rev_rotate_a(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)b;
	if (a->size < 2)
		return ;
	tmp = take_bottom(a);
	put_top(a, tmp);
}

void	rev_rotate_b(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)a;
	if (b->size < 2)
		return ;
	tmp = take_bottom(b);
	put_top(b, tmp);
}

void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate_a(a, b);
	rev_rotate_b(a, b);
}
