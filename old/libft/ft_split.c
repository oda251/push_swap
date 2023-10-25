/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:45:00 by yoda              #+#    #+#             */
/*   Updated: 2023/09/28 17:32:51 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	if (*s != c)
		count++;
	i = 0;
	while (s[i + 1])
	{
		if (s[i] == c && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**free_all(char ***dest, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free((*dest)[i]);
		i++;
	}
	free(*dest);
	return (NULL);
}

static int	initialize_split(char ***dest, char const *s, char c)
{
	size_t	size;

	if (!s)
	{
		(*dest) = NULL;
		return (0);
	}
	size = words_count(s, c);
	if (!*s)
	{
		(*dest) = ft_calloc(2, sizeof(char *));
		if (!*dest)
			return (0);
		(*dest)[1] = NULL;
		return (0);
	}
	*dest = malloc(sizeof(char *) * (size + 1));
	if (!*dest)
		return (0);
	(*dest)[size] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	const char	*start;
	size_t		index;

	if (!initialize_split(&dest, s, c))
		return (dest);
	start = NULL;
	index = 0;
	while (*s || start)
	{
		if (!*s || (start && *s == c))
		{
			dest[index] = malloc((s - start + 1) * sizeof(char));
			if (!dest[index])
				return (free_all(&dest, index));
			ft_strlcpy(dest[index++], start, s - start + 1);
			if (!*s)
				break ;
			start = NULL;
		}
		else if (!start && *s != c)
			start = s;
		s++;
	}
	return (dest);
}
