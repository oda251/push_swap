/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:38:58 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 06:40:40 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

void	rotate_a(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)b;
	if (a->size < 2)
		return ;
	tmp = take_top(a);
	put_bottom(a, tmp);
}

void	rotate_b(t_stack *a, t_stack *b)
{
	int	tmp;

	(void)a;
	if (b->size < 2)
		return ;
	tmp = take_top(b);
	put_bottom(b, tmp);
}

void	rotate_r(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	rotate_b(a, b);
}
