/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/29 00:24:02 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_small(t_stack *a, t_stack *b);
void	solve_rest(t_stack *a, t_stack *b, int size);

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
	if (size <= 100)
	{
		solve_rest(a, b, size);
		return (fix_position(a, b, start + size - 1));
	}
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
	// int	size;

	exec_certain_times(a, b, a->size, pb);
	// size = b->size;
	// solve_rest(a, b, size);
	// fix_position(a, b, size - 1);
	psl_sub(a, b, b->size, 0);
}


// void	push_swap_large(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = a->size;
// 	while (i < size)
// 	{
// 		if (a->nums[0] < size / 2)
// 			pb(a, b);
// 		else
// 			ra(a, b);
// 		i++;
// 	}
// 	psl_sub(a, b, b->size, 0);
// 	exec_certain_times(a, b, size - (size / 2), pb);
// 	psl_sub(a, b, size - size / 2, size / 2);
// }
