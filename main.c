/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:11:54 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 08:37:35 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	interpret_args(int c, char **v);
void	push_swap(t_stack *a, t_stack *b, int *count);
void	free_exit(t_stack a);

int	main(int c, char **v)
{
	t_stack	a;
	t_stack	b;
	int			count;

	if (c < 2)
		exit(0);
	a = interpret_args(c - 1, v + 1);
	if (!a.nums)
		error_exit();
	if (a.sorted == TRUE)
		free_exit(a);
	b.nums = malloc(sizeof(int) * a.size);
	if (!b.nums)
	{
		free(a.nums);
		error_exit();
	}
	b.size = 0;
	b.sorted = TRUE;
	// DONT FORGET TO DELETE THIS AND SO ON
	count = 0;
	push_swap(&a, &b, &count);
	// for (int i = 0; i < a.size; i++)
	// 	printf("%d ", a.nums[i]);
	// printf("\n");
	// printf("count: %d\n", count);
	free(a.nums);
	free(b.nums);
}
