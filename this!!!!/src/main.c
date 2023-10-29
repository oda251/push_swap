/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:11:54 by yoda              #+#    #+#             */
/*   Updated: 2023/10/29 18:41:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#ifndef SMALL_SIZE
# define SMALL_SIZE 6
#endif

t_stack	interpret_args(int c, char **v);
void	convert_consecutive(t_stack *dest);
void	push_swap_small(t_stack *a, t_stack *b);
void	push_swap_large(t_stack *a, t_stack *b);

int	main(int c, char **v)
{
	t_stack	a;
	t_stack	b;

	if (c < 2)
		exit(0);
	a = interpret_args(c - 1, v + 1);
	if (a.sorted == TRUE)
		free_exit(a);
	convert_consecutive(&a);
	b.nums = malloc(sizeof(int) * a.size);
	if (!b.nums)
	{
		free(a.nums);
		memory_error_exit();
	}
	b.size = 0;
	b.sorted = TRUE;
	if (a.size < SMALL_SIZE)
		push_swap_small(&a, &b);
	else
		push_swap_large(&a, &b);
	free(a.nums);
	free(b.nums);
}

// __attribute__((destructor))
// void	destructor(void)
// {
// 	int	status;

// 	status = system("leaks push_swap &> leaksout");
// 	if (status)
// 	{
// 		write(2, "leak!!!\n", 8);
// 		system("cat leaksout >/dev/stderr");
// 		exit(1);
// 	}
// }
