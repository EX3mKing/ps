/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnjak <bbosnjak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:26:20 by bbosnjak          #+#    #+#             */
/*   Updated: 2026/09/17 15:20:01 by bbosnjak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	fields(char *s, char *c)
{
	size_t	fields;

	fields = 0;
	while (*s)
	{
		while (ft_memchr(c, *s, ft_strlen(c)))
			s++;
		if (*s)
			fields++;
		while (*s && !ft_memchr(c, *s, ft_strlen(c)))
			s++;
	}
	return (fields);
}

static void	free_arr(char **out)
{
	int	i;

	i = 0;
	while (out[i])
	{
		free(out[i]);
		i++;
	}
	free(out[i]);
	free(out);
}

static char	**fill(char **out, char *s, char *c)
{
	size_t	field;
	int		l;

	field = 0;
	while (*s)
	{
		while (ft_memchr(c, *s, ft_strlen(c)))
			s++;
		if (*s)
		{
			l = 0;
			while (s[l] && !ft_memchr(c, s[l], ft_strlen(c)))
				l++;
			out[field] = ft_substr(s, 0, l);
			field++;
			if (!out)
			{
				free_arr(out);
				return (NULL);
			}
		}
		while (*s && !ft_memchr(c, *s, ft_strlen(c)))
			s++;
	}
	return (out);
}

char	**ft_split_extra(char *s, char *c)
{
	char	**out;
	size_t	f;

	if (!s)
		return (NULL);
	f = fields(s, c);
	out = (char **)malloc(sizeof(char *) * (f + 1));
	out[f] = NULL;
	if (!out)
		return (NULL);
	return (fill(out, s, c));
}
