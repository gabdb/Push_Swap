/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:41:03 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/26 00:12:15 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	lowest_half_list(t_head *head)
{
	int		i;
	int		half_len;
	int		first_count;
	int		last_count;
	t_node	*current;

	half_len = list_length(head) / 2;
	current = head->first;
	i = 0;
	first_count = 0;
	while (i++ < half_len)
	{
		first_count += current->value;
		current = current->next;
	}
	i = 0;
	last_count = 0;
	while (i++ < half_len)
	{
		last_count += current->value;
		current = current->next;
	}
	if (first_count >= last_count)
		return ('d');
	return ('u'); 
}
/*
	if (lowest_half_list(head_a) == 'u')
	{
		while (list_length(head_a) > 3)
		{
			if (head_a->first->value < ft_average(head_a))
				ft_push(head_a, head_b);
			else
				ft_rotate(head_a);
			count_op++;
		}
	}
	else
	{
		while (list_length(head_a) > 3)
		{
			if (head_a->first->value < ft_average(head_a))
				ft_push(head_a, head_b);
			else
				ft_rev_rotate(head_a);
			count_op++;
		}
	}
*/