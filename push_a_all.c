/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:43:10 by yoda              #+#    #+#             */
/*   Updated: 2023/10/12 04:00:01 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	(*choose(t_stack *a, int num))(t_stack *, t_stack *)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = -1;
	max = -1;
	while (++i < a->size)
	{
		if ((a->nums[i - 1] < num && a->nums[i] > num)
			|| (a->nums[i - 1] > a->nums[i] && a->nums[i - 1] < num))
		{
			if (min == -1)
				min = i;
			if (i > max)
				max = i;
		}
	}
	if (min < a->size - max)
		return (ra);
	else
		return (rra);
}

void	push_a_all(t_stack *a, t_stack *b)
{
	void	(*f)(t_stack *, t_stack *);

	while (b->size >= 0)
	{
		f = choose(a, b->nums[0]);
		if (b->nums[0] > a->nums[0]
			&& a->nums[0] && a->nums[0] > a->nums[a->size - 1])
			return (f(a, b));
		else
			return (pa(a, b));
	}
}
