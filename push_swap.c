/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:17:51 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 15:40:48 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	(*calc_both(t_stack a, t_stack b, int once_sorted))(t_stack *, t_stack *);

void	push_swap(t_stack *a, t_stack *b, int *count)
{
	void	(*f)(t_stack *, t_stack *);
	int		once_sorted;

	once_sorted = FALSE;
	while (TRUE)
	// for (int i = 0; i < 300; i++)
	{
		(*count)++;
		if (b->size == 0 && once_sorted == TRUE)
			break ;
		f = calc_both(*a, *b, once_sorted);
		if (*f == NULL)
			break ;
		f(a, b);
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
			once_sorted = TRUE;
	}
}
