/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_large_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 04:49:25 by yoda              #+#    #+#             */
/*   Updated: 2023/10/29 01:45:30 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*calc_b(t_stack b))(t_stack *, t_stack *);

static void	tlans_ans(int size, int ans, int *dest)
{
	if (ans <= size / 2)
	{
		dest[0] = ans;
		dest[1] = 0;
	}
	else
	{
		dest[0] = size - ans;
		dest[1] = 1;
	}
	return ;
}

static void	calc_times_to_rotate(int num, t_stack *s, int *dest)
{
	int	i;
	int	ans;

	i = -1;
	if (num < ft_min(s->nums, s->size))
		ans = ft_min_index(s->nums, s->size);
	else if (num > ft_max(s->nums, s->size))
		ans = ft_min_index(s->nums, s->size);
	while (++i < s->size)
	{
		if ((i > 0 && num > s->nums[i - 1]
				&& !(num > s->nums[i] && s->nums[i] != 0))
			|| (i == 0 && num > s->nums[s->size - 1]
				&& !(num > s->nums[i] && s->nums[i] != 0)))
		{
			ans = i;
			break ;
		}
	}
	tlans_ans(s->size, ans, dest);
	return ;
}

static void	exec_ans(t_stack *a, t_stack *b, int *ans)
{
	if (ans[1] == 0)
		exec_certain_times(a, b, ans[0], ra);
	else
		exec_certain_times(a, b, ans[0], rra);
	if (ans[3] == 0)
		exec_certain_times(a, b, ans[2], rb);
	else
		exec_certain_times(a, b, ans[2], rrb);
	pa(a, b);
}

void	solve_rest(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp[5];
	int	shortest[5];

	if (b->size <= 3)
	{
		while (is_sorted_b(*b) == FALSE)
			(calc_b(*b))(a, b);
	}
	while (b->size)
	{
		ft_bzero(shortest, sizeof(int) * 5);
		shortest[0] = INT_MAX;
		i = 0;
		while (i < b->size)
		{
			ft_bzero(tmp, sizeof(int) * 5);
			if (i <= b->size / 2)
				tmp[2] = i;
			else
			{
				tmp[2] = b->size - i;
				tmp[3] = 1;
			}
			calc_times_to_rotate(b->nums[i], a, tmp);
			tmp[4] = b->nums[i];
			if (shortest[0] + shortest[2] > tmp[0] + tmp[2]
				|| (shortest[0] + shortest[2] == tmp[0] + tmp[2] && shortest[4] < tmp[4]))
				ft_memcpy(shortest, tmp, sizeof(int) * 4);
			i++;
		}
		exec_ans(a, b, shortest);
	}
	// i = 0;
	// while (a->nums[i] != cp_size + start - 1)
	// 	i++;
	// if (i <= a->size / 2)
	// 	exec_certain_times(a, b, i + 1, ra);
	// else
	// 	exec_certain_times(a, b, a->size - 1 - i, rra);
}
