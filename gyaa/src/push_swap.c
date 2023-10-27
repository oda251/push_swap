/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/27 22:28:29 by yoda             ###   ########.fr       */
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

void	calc_times_to_rotate(int num, t_stack *s, int *dest)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		if (num > s->nums[i])
		{
			if (i <= s->size / 2)
			{
				dest[0] = s->size - i;
				dest[1] = 1;
			}
			else
				dest[0] = i;
			return ;
		}
	}
	return ;
}

void	solve_rest(t_stack *a, t_stack *b, int size, int start)
{
	int	i;
	int	cp_size;
	int	tmp[4];
	int	shortest[4];

	cp_size = size;
	while (size)
	{
		ft_bzero(shortest, sizeof(int) * 4);
		shortest[1] = INT_MAX;
		i = 0;
		while (i < size)
		{
			ft_bzero(tmp, sizeof(int) * 4);
			if (i <= size / 2)
				tmp[0] = i;
			else
			{
				tmp[0] = size - i;
				tmp[1] = 1;
			}
			calc_times_to_rotate(b->nums[i], a, tmp + 2);
			if (shortest[0] + shortest[2] > tmp[0] + tmp[2])
				ft_memcpy(shortest, tmp, sizeof(int) * 4);
			i++;
		}
		if (shortest[1] == 0)
			exec_certain_times(a, b, shortest[0], rb);
		else
			exec_certain_times(a, b, shortest[0], rrb);
		if (shortest[3] == 0)
			exec_certain_times(a, b, shortest[2], ra);
		else
			exec_certain_times(a, b, shortest[2], rra);
		pa(a, b);
		size--;
	}
	while (a->nums[a->size - 1] != cp_size + start - 1)
		ra(a, b);
}

void	psl_sub(t_stack *a, t_stack *b, int size, int start)
{
	int	i;

	i = 0;
	if (size <= 10)
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

