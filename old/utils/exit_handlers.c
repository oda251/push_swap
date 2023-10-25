/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 05:33:43 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 09:14:57 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_exit(t_stack stack)
{
	free(stack.nums);
	exit(0);
}

void	memory_error_exit(void)
{
	write(2, "Memory Error\n", 13);
	exit(0);
}

void	ko_exit(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

void	ok_exit(void)
{
	write(1, "OK\n", 3);
	exit(0);
}
