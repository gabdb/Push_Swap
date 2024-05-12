/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:51:53 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/11 23:37:43 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atoi(char *str)
{
	long	sign;
	long	res;

	sign = 1;
	res = 0;
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

int	find_min(t_node *origin)
{
	int		result;
	t_node	*ptr;

	result = origin->value;
	ptr = origin->next;
	while (ptr != NULL && ptr != origin)
	{
		if (ptr->value > result)
			result = ptr->value;
		ptr = ptr->next;
	}
	return (result);
}

