/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/15 05:01:09 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_small(t_stack *a, t_stack *b);
void	calc_large(t_stack *a, t_stack *b);
void	(*calc_a(t_stack a))(t_stack *, t_stack *);

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

void	push_swap_large(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	size;

	size = a->size;
	i = 0;
	while (size >> i)
	{
		j = 0;
		while (j++ < size)
		{
			if ((a->nums[0] >> i) & 1)
				ra(a, b);
			else
				pb(a, b);
		}
		while (b->size > 0)
			pa(a, b);
		i++;
	}
}
