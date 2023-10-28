/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:36:07 by yoda              #+#    #+#             */
/*   Updated: 2023/10/21 15:40:26 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_args(char **v)
{
	size_t	count;

	count = 0;
	if (!v)
		return (0);
	while (*v)
	{
		count++;
		if (count == 0)
			return (0);
		v++;
	}
	return (count);
}

char	**free_all_ps(char **v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		free(v[i]);
		i++;
	}
	free(v);
	return (NULL);
}

static char	**free_both_all(char **v1, char **v2)
{
	free_all_ps(v1);
	free_all_ps(v2);
	return (NULL);
}

static char	**join_strs(char **arr1, char **arr2)
{
	char			**dest;
	const size_t	len1 = count_args(arr1);
	const size_t	len2 = count_args(arr2);

	if (len2 == 0)
	{
		if (arr1)
			free_all_ps(arr1);
		error_exit();
	}
	if (len1 == 0)
		return (arr2);
	dest = malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!dest)
		return (free_both_all(arr1, arr2));
	ft_memcpy(dest, arr1, len1 * sizeof(char *));
	ft_memcpy(dest + len1, arr2, len2 * sizeof(char *));
	dest[len1 + len2] = NULL;
	free(arr1);
	free(arr2);
	return (dest);
}

char	**conv_str_arg(int c, char **v)
{
	char	**dest;
	char	**tmp;
	int		i;

	i = 0;
	while (i < c)
	{
		tmp = ft_split(v[i], ' ');
		dest = join_strs(dest, tmp);
		if (!dest)
			return (NULL);
		i++;
	}
	return (dest);
}
