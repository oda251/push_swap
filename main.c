/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:11:54 by yoda              #+#    #+#             */
/*   Updated: 2023/10/12 03:58:56 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	interpret_args(int c, char **v);
void	push_swap_small(t_stack *a, t_stack *b);

int	main(int c, char **v)
{
	t_stack	a;
	t_stack	b;

	if (c < 2)
		exit(0);
	a = interpret_args(c - 1, v + 1);
	if (a.sorted == TRUE)
		free_exit(a);
	b.nums = malloc(sizeof(int) * a.size);
	if (!b.nums)
	{
		free(a.nums);
		memory_error_exit();
	}
	b.size = 0;
	b.sorted = TRUE;
	if (a.size < 50)
		push_swap_small(&a, &b);
	else
		push_swap_large(&a, &b);
	// for (int i = 0; i < a.size; i++)
	// 	printf("%d ", a.nums[i]);
	// printf("\n");
	free(a.nums);
	free(b.nums);
}
