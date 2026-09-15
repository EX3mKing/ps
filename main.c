/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnjak <bbosnjak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:10:36 by bbosnjak          #+#    #+#             */
/*   Updated: 2026/09/15 17:58:33 by bbosnjak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>
// #include <string.h>
// #include <assert.h>

static int ft_flag_value(char *s)
{
	int flag = 0;
	if (ft_strcmp(s, "--simple") == 0)
		flag = F_SIMPLE;
	else if (ft_strcmp(s, "--medium") == 0)
		flag = F_MEDIUM;
	else if (ft_strcmp(s, "--complex") == 0)
		flag = F_COMPLEX;
	else if (ft_strcmp(s, "--adaptive") == 0)
		flag = F_ADAPTIVE;
	else if (ft_strcmp(s, "--bench") == 0)
		flag = F_BENCH;
	return (flag);
}

static int	ft_get_flags(t_data *data, char *argv[])
{
	int	flag;

	while (*(++argv) != NULL)
	{
		flag = ft_flag_value(*argv);
		if (flag == F_BENCH && data->bench != 0)
			return (0);
		if (flag == F_BENCH && data->bench == 0)
			data->bench = 1;
		if (flag > 0 && data->flag != 0)
			return (0);
		if (flag > 0 && data->flag == 0)
			data->flag = 1;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data data;

	if (argc < 2 && argv != NULL)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	ft_get_flags(&data, argv);
	return (0);
}
