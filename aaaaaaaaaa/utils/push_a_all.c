/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 02:43:10 by yoda              #+#    #+#             */
/*   Updated: 2023/10/15 03:46:07 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a_all(t_stack *a, t_stack *b)
{
	int		tmp[2];

	while (b->size > 0)
	{
		ft_bzero(tmp, sizeof(int) * 2);
		calc_times_to_rotate_a(b->nums[0], a, tmp);
		if (tmp[1] == 0)
			while (tmp[0]--)
				ra(a, b);
		else
			while (tmp[0]--)
				rra(a, b);
		pa(a, b);
	}
	ft_bzero(tmp, sizeof(int) * 2);
	calc_times_to_rotate_a(-1, a, tmp);
	if (tmp[1] == 0)
		while (tmp[0]--)
			ra(a, b);
	else
		while (tmp[0]--)
			rra(a, b);
}
