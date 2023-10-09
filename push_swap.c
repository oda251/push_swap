/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/10 03:04:12 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_both(t_stack *a, t_stack *b, int once_sorted);

void	push_swap(t_stack *a, t_stack *b)
{
	int		once_sorted;

	once_sorted = FALSE;
	while (TRUE)
	{
		if (a->sorted && b->size == 0)
			break ;
		calc_both(a, b, once_sorted);
		a->sorted = is_sorted_a(*a);
		b->sorted = is_sorted_b(*b);
		// printf("a: ");
		// for (int i = 0; i < a->size; i++)
		// 	printf("%d ", a->nums[i]);
		// printf("\n");
		// printf("b: ");
		// for (int i = 0; i < b->size; i++)
		// 	printf("%d ", b->nums[i]);
		// printf("\n");
		// printf("--------------------\n");
		if (a->sorted == TRUE && b->size == 0)
			break ;
		if (a->sorted == TRUE && b->sorted == TRUE)
			push_a_all(a, b);
	}
}
