/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:45:52 by yoda              #+#    #+#             */
/*   Updated: 2023/10/25 12:18:31 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"
# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int	*nums;
	int	size;
	int	sorted;
}	t_stack;
void	sa(t_stack *a, t_stack *b);
void	sb(t_stack *a, t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, t_stack *b);
void	rb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, t_stack *b);
void	rrb(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	push_a_all(t_stack *a, t_stack *b);
int		is_sorted_a(t_stack stack);
int		is_sorted_b(t_stack stack);
void	memory_error_exit(void);
void	free_exit(t_stack a);
void	error_exit(void);
void	calc_times_to_rotate_a(int num, t_stack *s, int *dest);
void	calc_times_to_rotate_b(int num, t_stack *s, int *dest);
void	exec_certain_times(
			t_stack *a, t_stack *b, int count, void (*f)(t_stack *, t_stack *));

#endif