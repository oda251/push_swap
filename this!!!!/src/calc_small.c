/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:26:43 by yoda              #+#    #+#             */
/*   Updated: 2023/10/12 04:08:13 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*calc_a(t_stack a))(t_stack *, t_stack *);
void	(*calc_b(t_stack b))(t_stack *, t_stack *);

void	calc_small(t_stack *a, t_stack *b)
{
	void	(*f_a)(t_stack *, t_stack*);
	void	(*f_b)(t_stack *, t_stack *);

	f_a = calc_a(*a);
	f_b = calc_b(*b);
	if (f_a == NULL && f_b == NULL)
	{
		if (!a->sorted)
			return (pb(a, b));
		else
			return (pa(a, b));
	}
	if (f_a == ra && f_b == rb)
		return (rr(a, b));
	else if (f_a == rra && f_b == rrb)
		return (rrr(a, b));
	else if (f_a == sa && f_b == sb)
		return (ss(a, b));
	else if (f_a)
		return (f_a(a, b));
	else
		return (f_b(a, b));
}
