/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_large_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 04:49:25 by yoda              #+#    #+#             */
/*   Updated: 2023/10/29 04:46:26 by yoda             ###   ########.fr       */
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

	if (num < ft_min(s->nums, s->size))
		ans = ft_min_index(s->nums, s->size);
	else if (num > ft_max(s->nums, s->size))
		ans = ft_min_index(s->nums, s->size);
	i = -1;
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
	if (ans[5] == 0)
		exec_certain_times(a, b, ans[4], rr);
	else
		exec_certain_times(a, b, ans[4], rrr);
	pa(a, b);
}

static void	update_shortest(int *tmp, int *shortest)
{
	if (tmp[1] == tmp[3])
	{
		tmp[5] = tmp[1];
		if (tmp[0] < tmp[2])
			tmp[4] = tmp[0];
		else
			tmp[4] = tmp[2];
		tmp[0] -= tmp[4];
		tmp[2] -= tmp[4];
	}
	if (shortest[0] + shortest[2] + shortest[4]
		> tmp[0] + tmp[2] + tmp[4])
		ft_memcpy(shortest, tmp, sizeof(int) * 6);
}

void	insert_b_to_a(t_stack *a, t_stack *b)
{
	int	i;
	int	tmp[6];
	int	shortest[6];

	while (b->size)
	{
		ft_bzero(shortest, sizeof(int) * 6);
		shortest[0] = INT_MAX;
		i = 0;
		while (i < b->size)
		{
			ft_bzero(tmp, sizeof(int) * 6);
			if (i <= b->size / 2)
				tmp[2] = i;
			else
			{
				tmp[2] = b->size - i;
				tmp[3] = 1;
			}
			calc_times_to_rotate(b->nums[i], a, tmp);
			update_shortest(tmp, shortest);
			i++;
		}
		exec_ans(a, b, shortest);
	}
}
