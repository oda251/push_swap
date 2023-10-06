/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_both.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:26:43 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 08:35:53 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*calc_a(t_stack a))(t_stack *, t_stack *);
void	(*calc_b(t_stack b))(t_stack *, t_stack *);

void	(*calc_both(t_stack a, t_stack b, int once_sorted))(t_stack *, t_stack *)
{
	void	(*f_a)(t_stack *, t_stack*);
	void	(*f_b)(t_stack *, t_stack *);

	f_a = calc_a(a);
	f_b = calc_b(b);
	if (once_sorted)
	{
		if (a.nums[0] > a.nums[a.size - 1] && a.nums[a.size - 1] > b.nums[0])
			return (rra);
		else if (a.nums[0] > b.nums[0])
			return (pa);
		else if (a.nums[0] < b.nums[0])
			return (ra);
		else
			return (rra);
	}
	if (f_a == NULL && f_b == NULL)
	{
		if (!a.sorted)
			return (pb);
		else
			return (pa);
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