/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 05:12:13 by yoda              #+#    #+#             */
/*   Updated: 2023/10/04 22:42:33 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	solve(char *str, const int sign)
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

long	check_integer(const char *str)
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
	nums = solve(trimmed + flag, sign);
	free(trimmed);
	return (nums);
}
