/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:33:55 by yoda              #+#    #+#             */
/*   Updated: 2023/10/13 06:49:42 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_large_ssub(t_num num, t_stack *b)
{
	int	i;

	if (b->nums[0] < num && num < b->nums[b->size - 1])
		return (i);
	else if (b->nums[0] < num && b->nums[b->size - 1] < b->nums[0])
		return (i);
	i = 1;
	while (i < b->size)
	{
		if (b->nums[i - 1] < b->nums[i])
		{
			if (b->nums[i] < num)
				return (i);
		}
		else if (b->nums[i - 1] > num && num > b->nums[i])
			return (i);
		i++;
	}
}

static void	calc_large_sub(t_stack *a, t_stack *b, int *min, int i)
{
	int	tmp;

	tmp = calc_large_ssub(a->nums[i], b);
	if (tmp + i < min[0])
	{
		min[0] = tmp + i;
		min[1] = i;
		min[2] = 0;
	}
	tmp = calc_large_ssub(a->nums[a->size - i], b);
	if (tmp + i < min[0])
	{
		min[0] = tmp + i;
		min[1] = i;
		min[2] = 1;
	}
}

void	calc_large(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp;
	int	min[3];

	i = 0;
	min[0] = INT_MAX;
	while (i <= a->size / 2)
	{
		calc_large_sub(a, b, min, i);
		if (min[0] == i)
			break ;
	}
}