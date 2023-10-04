/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:40:39 by yoda              #+#    #+#             */
/*   Updated: 2023/10/04 23:52:06 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		take_bottom(t_stack stack);
void	put_top(t_stack stack, int num);

void	rev_rotate_a(t_stack a, t_stack b)
{
	int	tmp;

	(void)b;
	if (a.size < 2)
		return ;
	tmp = take_bottom(a);
	put_top(a, tmp);
}

void	rev_rotate_b(t_stack a, t_stack b)
{
	int	tmp;

	(void)a;
	if (b.size < 2)
		return ;
	tmp = take_bottom(b);
	put_top(b, tmp);
}

void	rev_rotate_r(t_stack a, t_stack b)
{
	rev_rotate_a(a, b);
	rev_rotate_b(a, b);
}
