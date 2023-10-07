/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:26:43 by yoda              #+#    #+#             */
/*   Updated: 2023/10/08 06:27:33 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*calc_a(t_stack a))(t_stack *, t_stack *);
void	(*calc_b(t_stack b))(t_stack *, t_stack *);

static void	(*r_push_a(t_stack a, t_stack b))(t_stack *, t_stack *)
{
	if (b.size == 0)
		return (pa);
	if (b.nums[0] > a.nums[a.size - 1] && a.nums[0] > a.nums[a.size - 1])
		return (rra);
	else
		return (pa);
}

static void	(*r_push_b(t_stack a, t_stack b))(t_stack *, t_stack *)
{
	if (a.size == 0)
		return (pb);
	if (a.nums[0] > b.nums[b.size - 1] && b.nums[0] > b.nums[b.size - 1])
		return (rrb);
	else
		return (pb);
}

void	(*calc_both(t_stack a, t_stack b, int once_sorted))(t_stack *, t_stack *)
{
	void	(*f_a)(t_stack *, t_stack*);
	void	(*f_b)(t_stack *, t_stack *);

	f_a = calc_a(a);
	f_b = calc_b(b);
	if (once_sorted)
		return (r_push_a(a, b));
	if (f_a == NULL && f_b == NULL)
	{
		if (!a.sorted)
			return (r_push_b(a, b));
		else
			return (r_push_a(a, b));
	}
	if (!f_b)
		return (f_a);
	else if (!f_a)
		return (f_b);
	else
	{
		if (f_a == ra && f_b == rb)
			return (rr);
		else if (f_a == rra && f_b == rrb)
			return (rrr);
		else if (f_a == sa && f_b == sb)
			return (ss);
		else
			return (f_a);
	}
}