/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/29 02:49:31 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define PARTS 3

void	calc_small(t_stack *a, t_stack *b);
void	solve_rest(t_stack *a, t_stack *b);

void	push_swap_small(t_stack *a, t_stack *b)
{
	while (TRUE)
	{
		if (a->sorted && b->size == 0)
			break ;
		calc_small(a, b);
		a->sorted = is_sorted_a(*a);
		b->sorted = is_sorted_b(*b);
		if (a->sorted == TRUE && b->sorted == TRUE)
			break ;
	}
	push_a_all(a, b);
}

void	fix_position(t_stack *a, t_stack *b, int last)
{
	int	i;

	i = 0;
	while (a->nums[i] != last)
		i++;
	if (i <= a->size / 2)
		exec_certain_times(a, b, i + 1, ra);
	else
		exec_certain_times(a, b, a->size - 1 - i, rra);
}

void	move_split(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;
	int	part_size;

	i = 0;
	size = a->size;
	part_size = size / PARTS;
	while (i < PARTS)
	{
		j = 0;
		while (j++ < size - part_size * i)
		{
			if (a->nums[0] < part_size * (i + 1) || i == PARTS - 1)
				pb(a, b);
			else
				ra(a, b);
		}
		i++;
	}
}

void	push_swap_large(t_stack *a, t_stack *b)
{
	move_split(a, b);
	solve_rest(a, b);
	fix_position(a, b, a->size - 1);
}
