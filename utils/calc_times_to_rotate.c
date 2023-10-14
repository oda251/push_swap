/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_times_to_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 01:17:08 by yoda              #+#    #+#             */
/*   Updated: 2023/10/15 03:41:49 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_t_r_sub(int i, t_stack *s, int *dest)
{
	if (i <= s->size / 2)
	{
		dest[0] = i;
		dest[1] = 0;
	}
	else
	{
		dest[0] = s->size - i;
		dest[1] = 1;
	}
}

void	calc_times_to_rotate_a(int num, t_stack *a, int *dest)
{
	int	i;

	if (a->nums[0] > num && num > a->nums[a->size - 1])
		return ;
	else if (a->nums[0] > num && a->nums[a->size - 1] > a->nums[0])
		return ;
	i = 1;
	while (i < a->size)
	{
		if (a->nums[i - 1] > a->nums[i] && (a->nums[i - 1] < num || num < a->nums[i]))
			return (calc_t_r_sub(i, a, dest));
		else if (a->nums[i - 1] < num && num < a->nums[i])
			return (calc_t_r_sub(i, a, dest));
		i++;
	}
}

void	calc_times_to_rotate_b(int num, t_stack *b, int *dest)
{
	int	i;

	if (b->nums[0] < num && num < b->nums[b->size - 1])
		return ;
	else if (b->nums[0] < num && b->nums[b->size - 1] < b->nums[0])
		return ;
	i = 1;
	while (i < b->size)
	{
		if (b->nums[i - 1] < b->nums[i] && (b->nums[i - 1] > num || num > b->nums[i]))
			return (calc_t_r_sub(i, b, dest));
		else if (b->nums[i - 1] > num && num > b->nums[i])
			return (calc_t_r_sub(i, b, dest));
		i++;
	}
}
