/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:15:21 by yoda              #+#    #+#             */
/*   Updated: 2023/10/04 23:56:08 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		take_top(t_stack stack);
void	put_top(t_stack stack, int num);

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_a(t_stack a, t_stack b)
{
	(void)b;
	if (a.size < 2)
		return ;
	swap(&a.nums[0], &a.nums[1]);
}

void	swap_b(t_stack a, t_stack b)
{
	(void)a;
	if (b.size < 2)
		return ;
	swap(&b.nums[0], &b.nums[1]);
}

void	swap_s(t_stack a, t_stack b)
{
	if (a.size > 1)
		swap_a(a, b);
	if (b.size > 1)
		swap_b(a, b);
}
