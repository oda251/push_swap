/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:11:54 by yoda              #+#    #+#             */
/*   Updated: 2023/10/05 03:57:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	check_integer(const char *str);

static int	is_daplicated(int *nums, int amount, int num)
{
	while (--amount >= 0)
	{
		if (nums[amount] == num)
			return (1);
	}
	return (0);
}

static t_stack	interpret_args(int c, char **v)
{
	int			i;
	long		num;
	t_stack	dest;

	dest.nums = (int *)malloc(sizeof(int) * c);
	if (!dest.nums)
		return (dest);
	dest.size = c;
	i = 0;
	while (i < c)
	{
		num = check_integer(v[i]);
		if (num == LONG_MAX || is_daplicated(dest.nums, i, num))
		{
			free(dest.nums);
			dest.nums = NULL;
			return (dest);
		}
		dest.nums[i++] = num;
	}
	return (dest);
}

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int c, char **v)
{
	t_stack	a;
	t_stack	b;

	if (c < 2)
		exit(0);
	a = interpret_args(c - 1, v + 1);
	if (!a.nums)
		error_exit();
	b.nums = malloc(sizeof(int) * a.size);
	if (!b.nums)
	{
		free(a.nums);
		error_exit();
	}
	b.size = 0;
	push_swap(a, b);
	free(a.nums);
	free(b.nums);
}
