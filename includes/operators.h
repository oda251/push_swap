/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 06:27:36 by yoda              #+#    #+#             */
/*   Updated: 2023/10/07 06:31:57 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATORS_H
# define OPERATORS_H
# include "push_swap.h"

int		take_top(t_stack *stack);
int		take_bottom(t_stack *stack);
void	put_top(t_stack *stack, int num);
void	put_bottom(t_stack *stack, int num);
void	swap_a(t_stack *a, t_stack *b);
void	swap_b(t_stack *a, t_stack *b);
void	swap_s(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a, t_stack *b);
void	rotate_b(t_stack *a, t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);
void	rev_rotate_a(t_stack *a, t_stack *b);
void	rev_rotate_b(t_stack *a, t_stack *b);
void	rev_rotate_r(t_stack *a, t_stack *b);

#endif