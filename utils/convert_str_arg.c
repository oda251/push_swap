/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:36:07 by yoda              #+#    #+#             */
/*   Updated: 2023/10/19 22:52:58 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_args(char **v)
{
	int	count;

	count = 0;
	while (*v)
	{
		count++;
		v++;
	}
	return (count);
}

static void	free_all(char **v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
}

static 

char	**conv_str_arg(int c, char **v)
{
	char	**result;
	char	**new;
	char	**tmp;
	int		i;
	int		count;

	i = 0;
	while (v[i])
	{
		tmp = ft_split(v[i], ' ');
		if (!tmp)
			/* error */
		count += count_args(tmp);
		new = ft_calloc(count + 1, sizeof(char *));
		if (!new)
			/* error */
		i++;
	}
}
