/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_certain_times.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:16:54 by yoda              #+#    #+#             */
/*   Updated: 2023/10/25 12:17:04 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_certain_times(
	t_stack *a, t_stack *b, int count, void (*f)(t_stack *, t_stack *))
{
	int	i;

	i = 0;
	while (i < count)
	{
		f(a, b);
		i++;
	}
}
