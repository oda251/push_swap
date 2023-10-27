/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:43:59 by yoda              #+#    #+#             */
/*   Updated: 2023/10/27 19:47:33 by yoda             ###   ########.fr       */
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

int	is_sorted_with_size_a(t_stack a, int size)
{
	int	i;

	if (size <= 0)
		return (TRUE);
	i = 0;
	while (i < size - 1)
	{
		if (a.nums[i] > a.nums[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}