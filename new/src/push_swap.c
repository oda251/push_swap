/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/27 21:09:56 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_small(t_stack *a, t_stack *b);
void	(*calc_b(t_stack b))(t_stack *, t_stack *);

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

void	psl_ssub(t_stack *a, t_stack *b, int *size, int *start)
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
	if (size <= 3)
	{
		while (is_sorted_b(*b) == FALSE)
			(calc_b(*b))(a, b);
		exec_certain_times(a, b, size, pa);
		exec_certain_times(a, b, size, ra);
		return ;
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
	psl_ssub(a, b, &size, &start);
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
