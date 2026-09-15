/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnjak <bbosnjak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:12:04 by bbosnjak          #+#    #+#             */
/*   Updated: 2026/09/15 17:53:25 by bbosnjak         ###   ########.fr       */
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
	int				value;
	struct s_node *prev;
	struct s_node *next;
}					t_node;

typedef struct s_data
{
	t_node			*a;
	t_node			*b;
	unsigned int	sa;
	unsigned int	sb;
	unsigned int	ss;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rr;
	unsigned int	rra;
	unsigned int	rrb;
	unsigned int	rrr;
	int				flag;
	int				bench;
	double			disorder;
} t_data;

void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlen(char *s);
char	*ft_strstr(char *haystack, char *needle);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *s);

#endif
