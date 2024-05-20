/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:56:30 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/20 23:53:56 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_length(t_head *origin)
{
	t_node	*current;
	int		count;

	if (!origin)
		return (-1);
	else if (!origin->first)
		return (0);
	else if (origin->first == origin->first->next)
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

int index_max(t_head *origin)
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
	current = origin->first->next;;
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

int index_min(t_head *origin)
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
	current = origin->first->next;;
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

int	algo_merde(t_head *head_a, t_head *head_b)
{
	int		i;
	int		index;
	int		length;
	int		aantal_op;

	aantal_op = 0;
	length = list_length(head_a);
	while (length > 1)
	{
		index = index_min(head_a);
		if (index < (length / 2))
		{
			i = 0;
			while (i++ < index)
			{
				ft_rotate(head_a);
				aantal_op++;
			}
		}
		else
		{
			i = index;
			while (i++ < length)
			{
				ft_rev_rotate(head_a);
				aantal_op++;
			}
		}
		ft_push(head_a, head_b);
		aantal_op++;
		length--;
	}
	//aantal_op += ft_sort_3(head_a);
	while (head_b->first != NULL)
	{
		ft_push(head_b, head_a);
		aantal_op++;
	}
	return (aantal_op);
}
