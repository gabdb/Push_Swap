/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifty_hack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:10:43 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/03 13:16:18 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_list(int *list, t_head *head)
{
	int	i;
	int	len;
	int	min;
	int	min_index;

	len = list_length(head);
	i = 0;
	min = 2147483647;
	min_index = 0;
	while (i < len)
	{
		if (list[i] < min)
		{
			min = list[i];
			min_index = i;
		}
		i++;
	}
	list[min_index] = 2147483647;
	return (min);
}

void	fill_list(int *list, t_head *head)
{
	int		i;
	t_node	*current;

	*list = head->first->value;
	current = head->first->next;
	i = 0;
	while (current != head->first)
	{
		i++;
		list[i] = current->value;
		current = current->next;
	}
}

int	is_smallest_50(int value, t_head *head)
{
	int		list[10000];
	int		array[100];
	int		i;

	fill_list(list, head);
	i = 0;
	while (i < 80)
	{
		array[i] = find_min_list(list, head);
		i++;
	}
	i = 0;
	while (i < 80)
	{
		if (value == array[i])
			return (1);
		i++;
	}
	return (0);
}
