/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_operator_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 03:54:54 by yoda              #+#    #+#             */
/*   Updated: 2023/10/05 03:55:52 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_r(t_stack a, t_stack b);

void	rrr(t_stack a, t_stack b)
{
	rev_rotate_r(a, b);
	write(1, "rrr\n", 4);
}
