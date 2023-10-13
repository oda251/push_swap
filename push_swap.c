/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/13 22:35:35 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_small(t_stack *a, t_stack *b);
void	calc_large(t_stack *a, t_stack *b);
void	(*calc_a(t_stack a))(t_stack *, t_stack *);

void	push_swap_small(t_stack *a, t_stack *b)
{
	int		once_sorted;

	once_sorted = FALSE;
	while (TRUE)
	{
		if (a->sorted && b->size == 0)
			break ;
		calc_small(a, b);
		a->sorted = is_sorted_a(*a);
		b->sorted = is_sorted_b(*b);
		if (a->sorted == TRUE && b->size == 0)
			break ;
		if (a->sorted == TRUE && b->sorted == TRUE)
			push_a_all(a, b);
	}
}

void	push_swap_large(t_stack *a, t_stack *b)
{
	void	(*f)(t_stack *, t_stack *);

	pb(a, b);
	pb(a, b);
	for (int i=0; i<3; i++)
	// while (a->size > 3)
		calc_large(a, b);
	// while (!a->sorted)
	// {
	// 	f = calc_a(*a);
	// 	f(a, b);
	// 	a->sorted = is_sorted_a(*a);
	// }
	for (int i = 0; i < b->size; i++)
		printf("%d ", b->nums[i]);
	printf("\n");
	// push_a_all(a, b);
}

		// printf("a: ");
		// for (int i = 0; i < a->size; i++)
		// 	printf("%d ", a->nums[i]);
		// printf("\n");
		// printf("b: ");
		// for (int i = 0; i < b->size; i++)
		// 	printf("%d ", b->nums[i]);
		// printf("\n");
		// printf("--------------------\n");