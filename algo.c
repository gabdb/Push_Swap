/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:56:30 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 17:33:18 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_length(t_head *origin)
{
	t_node	*current;
	int		count;

	if (!origin)
		return (-1);
	else if (!origin->first)
		return (0);
	else if (origin->first == origin->last)
		return (1);
	count = 1;
	current = origin->first->next;
	while (current != origin->first)
	{
		count += 1;
		current = current->next;
	}
	return (count);
}

int	index_max(t_head *origin)
{
	t_node	*current;
	int		index;
	int		save_index;
	int		maximum;

	if (!origin || !origin->first)
		return (-1);
	if (origin->first == origin->last)
		return (0);
	index = 1;
	save_index = 0;
	maximum = origin->first->value;
	current = origin->first->next;
	while (current != origin->first)
	{
		if (current->value > maximum)
		{
			maximum = current->value;
			save_index = index;
		}
		index++;
		current = current->next;
	}
	return (save_index);
}

int	index_min(t_head *origin)
{
	t_node	*current;
	int		index;
	int		save_index;
	int		minimum;

	if (!origin || !origin->first)
		return (-1);
	if (origin->first == origin->last)
		return (0);
	index = 1;
	save_index = 0;
	minimum = origin->first->value;
	current = origin->first->next;
	while (current != origin->first)
	{
		if (current->value < minimum)
		{
			minimum = current->value;
			save_index = index;
		}
		index++;
		current = current->next;
	}
	return (save_index);
}

void	ft_sort_3(t_head *head, char q)
{
	if (index_max(head) == 0)
		ft_rotate(head, q);
	else if (index_max(head) == 1)
		ft_rev_rotate(head, q);
	if (head->first->value > head->first->next->value)
		ft_swap(head, q);
}
