/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnjak <bbosnjak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 15:03:46 by ashysh            #+#    #+#             */
/*   Updated: 2026/09/17 16:15:54 by bbosnjak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digits(const char *s)
{
	int	i;

	i = 0;
	if(s[i] == '-' || s[i] == '+')
		i++;
	if(!s[i])
		return(0);
	while(s[i])
	{
		if(s[i] < '0' || s[i] > '9')
			return(0);
		i++;
	}
	return(1);
}

int	ft_ps_atoi(const char *s, int *ok)
{
	int i;
	int sign;
	long result;

	i = 0;
	sign = 1;
	result = 0;
	*ok = 0;
	if(s[i] == '-' || s[i] == '+')
	{
		if(s[i] == '-')
			sign = -sign;
		i++;
	}
	while(s[i])
	{
		result = result * 10 + (s[i] - '0');
		if(sign > 0 && result > 2147483647L)
			return(0);
		if(sign < 0 && result > 2147483648L)
			return(0);
		i++;
	}
	*ok = 1;
	return((int)(result*sign));
}
