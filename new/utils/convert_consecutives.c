/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_consecutives.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 07:18:17 by yoda              #+#    #+#             */
/*   Updated: 2023/10/15 19:00:23 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	solve(t_stack *d, int *new)
{
	int		i;
	int		min_i;
	int		num;
	long	smallest;

	smallest = LONG_MIN;
	num = 0;
	min_i = 0;
	while (num < d->size)
	{
		i = -1;
		while (++i < d->size)
		{
			if (d->nums[min_i] == smallest && (long) d->nums[i] > smallest)
				min_i = i;
			else
			{
				if (d->nums[i] < d->nums[min_i] && d->nums[i] > smallest)
					min_i = i;
			}
		}
		new[min_i] = num++;
		smallest = d->nums[min_i];
	}
}

void	convert_consecutive(t_stack *d)
{
	int		*new;

	new = malloc(sizeof(int) * d->size);
	if (!new)
	{
		free(d->nums);
		memory_error_exit();
	}
	solve(d, new);
	free(d->nums);
	d->nums = new;
}
