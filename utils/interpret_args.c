/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:12:13 by yoda              #+#    #+#             */
/*   Updated: 2023/10/08 07:28:22 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert_consecutive(t_stack *dest);

static long	atoi_ps(char *str, const int sign)
{
	unsigned long	num;

	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		if (sign > 0)
		{
			if (num > (unsigned long) INT_MAX)
				return (LONG_MAX);
		}
		else if (num > (unsigned long) INT_MAX + 1)
			return (LONG_MAX);
		str++;
	}
	if (*str != '\0')
		return (LONG_MAX);
	return (sign * num);
}

static long	check_integer(const char *str)
{
	int		sign;
	char	*trimmed;
	long	nums;
	int		flag;

	trimmed = ft_strtrim(str, " \t\v\r\f");
	if (!ft_isdigit(*trimmed) && *trimmed != '-' && *trimmed != '+')
	{
		free(trimmed);
		return (LONG_MAX);
	}
	sign = 1;
	flag = 0;
	if (*trimmed == '-')
	{
		sign = -1;
		flag++;
	}
	else if (*trimmed == '+')
		flag++;
	nums = atoi_ps(trimmed + flag, sign);
	free(trimmed);
	return (nums);
}

static int	is_daplicated(int *nums, int amount, int num)
{
	while (--amount >= 0)
	{
		if (nums[amount] == num)
			return (1);
	}
	return (0);
}

t_stack	interpret_args(int c, char **v)
{
	int			i;
	
	long		num;
	t_stack	dest;

	dest.nums = (int *)malloc(sizeof(int) * c);
	if (!dest.nums)
		memory_error_exit();
	dest.size = c;
	i = 0;
	while (i < c)
	{
		num = check_integer(v[i]);
		if (num == LONG_MAX || is_daplicated(dest.nums, i, num))
		{
			free(dest.nums);
			error_exit();
		}
		dest.nums[i++] = num;
	}
	convert_consecutive(&dest);
	dest.sorted = is_sorted_a(dest);
	return (dest);
}
