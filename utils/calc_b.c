/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 01:09:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 07:58:48 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	(*calc_b_over_2(t_stack b))(t_stack *, t_stack *)
{
	if (b.nums[0] > b.nums[1])
	{
		if (b.nums[0] > b.nums[b.size - 1])
		{
			if (b.nums[1] >= b.nums[b.size - 1])
				return (NULL);
			else
				return (rrb);
		}
		else
			return (rrb);
	}
	else
	{
		if (b.nums[0] > b.nums[b.size - 1])
			return (sb);
		else
		{
			if (b.nums[1] > b.nums[b.size - 1])
				return (rb);
			else
				return (sb);
		}
	}
}

void	(*calc_b(t_stack b))(t_stack *, t_stack *)
{
	if (b.size < 2)
		return (NULL);
	else
		return (calc_b_over_2(b));
}
