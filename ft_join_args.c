/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnjak <bbosnjak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 15:24:06 by bbosnjak          #+#    #+#             */
/*   Updated: 2026/09/17 16:12:30 by bbosnjak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_join_args(char **args)
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (args == NULL)
		return (0);
	len = 0;
	ret = NULL;
	i = 0;
	while(args[i])
		len += ft_strlen(args[i++]);
	ret = malloc(len + i + 1);
	len = 0;
	while (*args)
	{
		ft_memcpy(&ret[len], *args, ft_strlen(*args));
		len += ft_strlen(*args);
		if (*(args + 1) != NULL)
			ret[len] = ' ';
		len++;
		args++;
	}
	return (ret);
}
