/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnjak <bbosnjak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:12:04 by bbosnjak          #+#    #+#             */
/*   Updated: 2026/09/17 16:50:36 by bbosnjak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define F_SIMPLE 1
# define F_MEDIUM 2
# define F_COMPLEX 3
# define F_ADAPTIVE 4
# define F_BENCH 5

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "limits.h"

typedef struct s_node
{
	int 	value;
	int 	index;
	struct s_node *prev;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	t_node *bottom;
	int size;
}	t_stack;

typedef struct s_data
{
	t_stack a;
	t_stack b;
	int	sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int strategy;
	int bench;
	double disorder;
}	t_data;

void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(char *s);
char	*ft_strstr(char *haystack, char *needle);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split_extra(char *str, char *set);
char	*ft_join_args(char **args);
int		ft_ps_atoi(const char *s, int *ok);
int		ft_is_digits(const char *s);
int		stack_fill(t_stack *s, int *value, int count);
t_node	*node_new(int value);
void	stack_init(t_stack *s);
void	stacck_append(t_stack *s, t_node *node);
void	stack_clear(t_stack *s);

#endif
