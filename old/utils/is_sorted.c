/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:43:59 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 06:51:40 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size - 1)
	{
		if (stack.nums[i] > stack.nums[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_sorted_b(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.size - 1)
	{
		if (stack.nums[i] < stack.nums[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
