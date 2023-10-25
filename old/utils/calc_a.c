/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 01:09:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/15 18:59:43 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	(*calc_a_over_2(t_stack a))(t_stack *s1, t_stack *s2)
{
	if (a.nums[0] < a.nums[1])
	{
		if (a.nums[0] < a.nums[a.size - 1])
		{
			if (a.nums[1] <= a.nums[a.size - 1])
				return (NULL);
			else
				return (sa);
		}
		else
			return (rra);
	}
	else
	{
		if (a.nums[0] < a.nums[a.size - 1])
			return (sa);
		else
		{
			if (a.nums[1] < a.nums[a.size - 1])
				return (ra);
			else
				return (sa);
		}
	}
}

void	(*calc_a(t_stack a))(t_stack *s1, t_stack *s2)
{
	if (a.size < 2)
		return (NULL);
	else
		return (calc_a_over_2(a));
}
