/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:33:55 by yoda              #+#    #+#             */
/*   Updated: 2023/10/13 23:13:38 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calc_large_sssub(int i, t_stack *b, int *dest)
{
	if (i <= b->size / 2)
	{
		dest[0] = i;
		dest[1] = 0;
	}
	else
	{
		dest[0] = b->size - i;
		dest[1] = 1;
	}
	return ;
}

// find a position to push a number of 'a' to 'b'
static void	calc_large_ssub(int num, t_stack *b, int *dest)
{
	int	i;

	if (b->nums[0] < num && num < b->nums[b->size - 1])
		return ;
	else if (b->nums[0] < num && b->nums[b->size - 1] < b->nums[0])
		return ;
	i = 1;
	while (i < b->size)
	{
		if ((b->nums[i - 1] < b->nums[i] && b->nums[i] < num) || (b->nums[i - 1] < b->nums[i] && b->nums[i - 1] > num))
			return (calc_large_sssub(i, b, dest));
		else if (b->nums[i - 1] > num && num > b->nums[i])
			return (calc_large_sssub(i, b, dest));
		i++;
	}
}

static void	calc_large_sub(t_stack *a, t_stack *b, int *min, int i)
{
	int	tmp[2];

	ft_bzero(tmp, sizeof(int) * 2);
	calc_large_ssub(a->nums[i], b, tmp);
	if (tmp[0] + i < min[0])
	{
		min[0] = tmp[0] + i;
		min[1] = i;
		min[2] = 0;
		min[3] = tmp[1];
		// printf("num = %d\n", a->nums[i]);
		// printf("min[0] = %d\n", min[0]);
		// printf("min[1] = %d\n", min[1]);
		// printf("min[2] = %d\n", min[2]);
		// printf("min[3] = %d\n", min[3]);
	}
	calc_large_ssub(a->nums[a->size - i], b, tmp);
	if (tmp[0] + i < min[0])
	{
		min[0] = tmp[0] + i;
		min[1] = i;
		min[2] = 1;
		min[3] = tmp[1];
		// printf("num = %d\n", a->nums[a->size - i]);
		// printf("min[0] = %d\n", min[0]);
		// printf("min[1] = %d\n", min[1]);
		// printf("min[2] = %d\n", min[2]);
		// printf("min[3] = %d\n", min[3]);
	}
}

void	calc_large(t_stack *a, t_stack *b)
{
	int	i;
	int	min[4];

	i = 0;
	min[0] = INT_MAX;
	while (i <= a->size / 2)
	{
		calc_large_sub(a, b, min, i);
		if (min[0] == i++)
			break ;
	}
	printf("min[0] = %d\n", min[0]);
	printf("min[1] = %d\n", min[1]);
	printf("min[2] = %d\n", min[2]);
	printf("min[3] = %d\n", min[3]);
	min[0] = min[0] - min[1];
	if (min[1] > 0 && min[2] == 0)
	{
		while (min[1]--)
			ra(a, b);
	}
	else if (min[1] > 0)
	{
		while (min[1]--)
			rra(a, b);
	}
	if (min[0] > 0 && min[3] == 0)
	{
		while (min[0]--)
			rb(a, b);
	}
	if (min[0] > 0)
	{
		while (min[0]--)
			rrb(a, b);
	}
	pb(a, b);
}
