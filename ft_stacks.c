/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashysh <ashysh@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 16:27:12 by ashysh            #+#    #+#             */
/*   Updated: 2026/09/11 17:25:10 by ashysh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_fill(t_stack *s, int *value, int count)
{
	int i;
	t_node *node;

	i = 0;
	while(i < count)
	{
		node = node_new(value[i]);
		if(!node)
		{
			stack_clear(s);
			return(0);
		}
		stacck_append(s, node);
		i++;
	}
	return(1);
}

t_node *node_new(int value)
{
	t_node *node;
	node = malloc(sizeof(t_node));
	if(!node)
		return NULL;
	node->value = value;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	return(node);
}

void stack_init(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

void stacck_append(t_stack *s, t_node *node)
{
	if(s->bottom == NULL)
	{
		s->top = node;
		s->bottom = node;
	}
	else
	{
		node->prev = s->bottom;
		s->bottom->next = node;
		s->bottom = node;
	}
	s->size++;
}

void stack_clear(t_stack *s)
{
	t_node *tmp;
	t_node *next;

	tmp = s->top;
	while(tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	stack_init(s);
}

