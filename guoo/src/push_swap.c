/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/28 21:53:25 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_small(t_stack *a, t_stack *b);
void	solve_rest(t_stack *a, t_stack *b, int size, int start);

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

void	skip_sorted(t_stack *a, t_stack *b, int *size, int *start)
{
	while (a->nums[0] == *start && *size)
	{
		ra(a, b);
		(*start)++;
		(*size)--;
	}
}

void	psl_sub(t_stack *a, t_stack *b, int size, int start)
{
	int	i;

	i = 0;
	if (size <= 30)
		return (solve_rest(a, b, size, start));
	while (i < size)
	{
		if (b->nums[0] >= start + (size / 2))
			pa(a, b);
		else
			rb(a, b);
		i++;
	}
	psl_sub(a, b, size / 2, start);
	start += size / 2;
	size -= size / 2;
	skip_sorted(a, b, &size, &start);
	if (size)
	{
		exec_certain_times(a, b, size, pb);
		psl_sub(a, b, size, start);
	}
}

void	push_swap_large(t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (a->nums[0] < size / 2)
			pb(a, b);
		else
			ra(a, b);
		i++;
	}
	psl_sub(a, b, b->size, 0);
	exec_certain_times(a, b, size - (size / 2), pb);
	psl_sub(a, b, size - size / 2, size / 2);
}
