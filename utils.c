/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:51:53 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 17:53:18 by gnyssens         ###   ########.fr       */
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

int	value_at_index(t_head *head, int index)
{
	t_node	*current;
	int		i;

	current = head->first;
	i = 0;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

double	ft_average(t_head *head)
{
	double	count;
	double	length;
	t_node	*current;

	length = list_length(head);
	count = head->first->value;
	current = head->first->next;
	while (current != head->first)
	{
		count += current->value;
		current = current->next;
	}
	return (count / length);
}

void	min_on_top(t_head *head, char q)
{
	int	index;
	int	len;

	len = list_length(head);
	index = index_min(head);
	if (index <= (len / 2))
	{
		while (index-- > 0)
			ft_rotate(head, q);
	}
	else
	{
		while (index++ < len)
			ft_rev_rotate(head, q);
	}
}
