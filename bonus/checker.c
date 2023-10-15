/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:15:50 by yoda              #+#    #+#             */
/*   Updated: 2023/10/15 18:59:03 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_checker.h"

char	*get_next_line(int fd);
int		solve_checker(t_stack *a, t_stack *b);
int		checker_sub(t_stack *a, t_stack *b, char *line);
int		ps_strcmp(const char *s1, const char *s2);

int	main(int c, char **v)
{
	t_stack	a;
	t_stack	b;
	int		result_flag;

	if (c < 2)
		exit(0);
	a = interpret_args(c - 1, v + 1);
	if (is_sorted_a(a) == TRUE)
		free_exit(a);
	b.nums = malloc(sizeof(int) * a.size);
	if (!b.nums)
	{
		free(a.nums);
		memory_error_exit();
	}
	b.size = 0;
	result_flag = solve_checker(&a, &b);
	free(a.nums);
	free(b.nums);
	if (result_flag == OK)
		ok_exit();
	else if (result_flag == KO)
		ko_exit();
	else
		error_exit();
}

int	solve_checker(t_stack *a, t_stack *b)
{
	int		result_flag;
	char	*line;

	result_flag = ERROR;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		result_flag = checker_sub(a, b, line);
		if (result_flag == ERROR)
		{
			free(line);
			break ;
		}
		free(line);
	}
	if (result_flag != ERROR)
		result_flag = is_sorted_a(*a) && b->size == 0;
	return (result_flag);
}

int	checker_sub(t_stack *a, t_stack *b, char *line)
{
	if (ps_strcmp(line, "sa") == 1)
		swap_a(a, b);
	else if (ps_strcmp(line, "sb") == 1)
		swap_b(a, b);
	else if (ps_strcmp(line, "ss") == 1)
		swap_s(a, b);
	else if (ps_strcmp(line, "pa") == 1)
		push_a(a, b);
	else if (ps_strcmp(line, "pb") == 1)
		push_b(a, b);
	else if (ps_strcmp(line, "ra") == 1)
		rotate_a(a, b);
	else if (ps_strcmp(line, "rb") == 1)
		rotate_b(a, b);
	else if (ps_strcmp(line, "rr") == 1)
		rotate_r(a, b);
	else if (ps_strcmp(line, "rra") == 1)
		rev_rotate_a(a, b);
	else if (ps_strcmp(line, "rrb") == 1)
		rev_rotate_b(a, b);
	else if (ps_strcmp(line, "rrr") == 1)
		rev_rotate_a(a, b);
	else
		return (ERROR);
	return (OK);
}
