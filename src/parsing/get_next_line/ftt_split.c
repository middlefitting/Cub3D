/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechung <sechung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:33:34 by tyi               #+#    #+#             */
/*   Updated: 2023/05/15 16:14:18 by sechung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while ((*s == c) && *s)
			s ++;
		if (*s != c && *s)
			i ++;
		while ((*s != c) && *s)
			s ++;
	}
	return (i);
}

char	*strdup1(char const *src, size_t l)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (l + 1));
	if (!p)
		return (0);
	while (i < l)
	{
		p[i] = src[i];
		i ++;
	}
	p[i] = 0;
	return (p);
}

void	ftt_memfree(char **s, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		free(*s + i);
		i++;
	}
	free(s);
}

size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char	**ftt_split(char const *s, char c)
{
	char	**str;
	size_t	i;

	if (!s)
		return (0);
	str = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		while ((*s == c) && *s)
			s ++;
		if (*s != c && *s)
			str[i++] = strdup1(s, word_len(s, c));
		if (!(long)strdup1)
		{
			ftt_memfree(str, i);
			return (0);
		}
		while ((*s != c) && *s)
			s++;
	}
	str[i] = 0;
	return (str);
}
