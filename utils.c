/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:51:53 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/09 00:05:15 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atoi(char *str)
{
	long	sign;
	long	res;
	long	buff;

	sign = 1;
	res = 0;
	buff = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= (-1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str++ - '0';
		if (res < -2147483648)
			return (-2147483649);
		if (res > 2147483647)
			return (2147483649);
	}
	return (sign * res);
}

int	my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}