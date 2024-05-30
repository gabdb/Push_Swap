/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:41:03 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 17:53:29 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_head *head)
{
	t_node	*current;
	int		max;

	current = head->first;
	max = current->value;
	while (current != head->last)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	if (current->value > max)
		max = current->value;
	return (max);
}

int	ft_min(t_head *head)
{
	t_node	*current;
	int		min;

	current = head->first;
	min = current->value;
	while (current != head->last)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	if (current->value < min)
		min = current->value;
	return (min);
}
