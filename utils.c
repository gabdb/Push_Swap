/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:51:53 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/23 19:45:18 by gnyssens         ###   ########.fr       */
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


void	print_stack(t_head *head)
{
	t_node *current = head->first;

	if (!head || !head->first)
	{
		printf("stack est vide ! (ou head pas init)\n\n");
		return ;
	}
	while (current != head->last)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("%d\n\n", head->last->value);
}

int	ft_small(int a, int b) //promo en utilisant rr / rrr
{
	if (a < b)
		return (a);
	else
		return (b);
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
