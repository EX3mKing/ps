/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnjak <bbosnjak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:10:36 by bbosnjak          #+#    #+#             */
/*   Updated: 2026/09/17 17:02:04 by bbosnjak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// returns 0 if its not good and 1 if it is
#include <stdio.h>
int	handle_args(char **args, t_data *data)
{
	int	flag;
	int	ok;

	while (*(++args) != NULL)
	{
		flag = ft_flag_value(*args);
		if (flag == F_BENCH && data->bench != 0)
			return (0);
		if (flag == F_BENCH && data->bench == 0)
			data->bench = 1;
		if (flag > 0 && data->strategy != 0)
			return (0);
		if (flag > 0 && data->strategy == 0)
			data->strategy = 1;
		if (flag == 0 && !ft_is_digits(*args))
			return (0);
		if (flag == 0 && ft_is_digits(*args))
		{
			stacck_append(&data->a, node_new(ft_ps_atoi(*args, &ok)));
			printf("append to stack: %s\n", *args);
			if (ok == 0)
				return (0);
		}
	}
	return (1);
}

void	print_stack(t_data *data)
{
	t_node *tmp;
	t_node *next;

	tmp = data->a.top;
	while(tmp)
	{
		next = tmp->next;
		printf("val %d, index %d\n", tmp->value, tmp->index);
		tmp = next;
	}
}

int	main(int argc, char *argv[])
{
	t_data data;
	char **args;

	if (argc < 2 && argv != NULL)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	args = ft_split_extra(ft_join_args(argv), " \f\n\t\r\v");
	stack_init(&data.a);
	if (!handle_args(args, &data))
	{
		printf("Error\n");
		stack_clear(&data.a);
		return (1);
	}
	print_stack(&data);
	return (0);
}
