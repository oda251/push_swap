/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:45:52 by yoda              #+#    #+#             */
/*   Updated: 2023/10/05 03:57:00 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int	*nums;
	int	size;
}	t_stack;
void	push_swap(t_stack a, t_stack b);
void	sa(t_stack a, t_stack b);
void	sb(t_stack a, t_stack b);
void	ss(t_stack a, t_stack b);
void	pa(t_stack a, t_stack b);
void	pb(t_stack a, t_stack b);
void	ra(t_stack a, t_stack b);
void	rb(t_stack a, t_stack b);
void	rr(t_stack a, t_stack b);
void	rra(t_stack a, t_stack b);
void	rrb(t_stack a, t_stack b);
void	rrr(t_stack a, t_stack b);
int		is_sorted(t_stack stack);

#endif