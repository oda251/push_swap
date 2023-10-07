/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:18:17 by yoda              #+#    #+#             */
/*   Updated: 2023/10/08 07:27:49 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve(t_stack *dest, int *new)
{
	int		i;
	int		min_i;
	int		num;
	long	smallest;

	smallest = LONG_MIN;
	num = 1;
	while (num <= dest->size)
	{
		i = -1;
		while (++i < dest->size)
		{
			if (dest->nums[min_i] == smallest && (long) dest->nums[i] > smallest)
				min_i = i;
			else
			{
				if (dest->nums[i] < dest->nums[min_i] && dest->nums[i] > smallest)
					min_i = i;
			}
		}
		new[min_i] = num++;
		smallest = dest->nums[min_i];
	}
}

void	convert_consecutive(t_stack *dest)
{
	int		*new;
	
	new = malloc(sizeof(int) * dest->size);
	if (!new)
	{
		free(dest->nums);
		memory_error_exit();
	}
	solve(dest, new);
	free(dest->nums);
	dest->nums = new;
}