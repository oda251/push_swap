/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 23:37:00 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 06:40:54 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

int	take_top(t_stack *stack)
{
	int	tmp;

	tmp = stack->nums[0];
	stack->size--;
	ft_memmove(stack->nums, stack->nums + 1, sizeof(int) * (stack->size));
	return (tmp);
}

void	put_top(t_stack *stack, int num)
{
	ft_memmove(stack->nums + 1, stack->nums, sizeof(int) * stack->size);
	stack->nums[0] = num;
	stack->size++;
}

int	take_bottom(t_stack *stack)
{
	int	tmp;

	tmp = stack->nums[stack->size - 1];
	stack->size--;
	return (tmp);
}

void	put_bottom(t_stack *stack, int num)
{
	stack->nums[stack->size] = num;
	stack->size++;
}
