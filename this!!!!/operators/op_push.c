/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:22:26 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 06:29:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

void	push_a(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->size < 1)
		return ;
	tmp = take_top(b);
	put_top(a, tmp);
}

void	push_b(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size < 1)
		return ;
	tmp = take_top(a);
	put_top(b, tmp);
}
