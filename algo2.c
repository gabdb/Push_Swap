/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:25:19 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/20 18:59:26 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_bf(int value, t_head *head)
{
	int 	index;
	t_node	*current;

	current = head->first;
	index = 0;
	while (current != head->last)
	{
		if (value < current->previous->value && value > current->value)
			return (index);
		index++;
		current = current->next;
	}
}

int ft_min(t_head *head)
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
	return (min);
}

int ft_max(t_head *head)
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
	return (max);
}

int	ft_rev_sort_3(t_head *head)
{
	int	count_op;

	count_op = 0;
	if (index_min(head) == 0)
	{
		ft_rotate(head);
		count_op++;
	}  
	else if (index_min(head) == 1)
	{
		ft_rev_rotate(head);
		count_op++;
	}
	if (head->first->value < head->first->next->value)
	{
		ft_swap(head);
		count_op++;
	}
	return (count_op);
}

int	cost_rotate(int value, t_head *head)
{
	int	cost;

	cost = 0;
	if (value > ft_max(head) || value < ft_min(head))
		cost = index_max(head);
	else
		cost = index_bf(value, head);
}

int	cost_rev_rotate(int value, t_head *head)
{
	int	cost;

	cost = 0;
	if (value > ft_max(head) || value < ft_min(head))
		cost = list_length(head) - index_max(head);
	else
		cost = list_length(head) - index_bf(value, head);
}

int	algo_nul(t_head *head_a, t_head *head_b)
{
	int		i;
	int		len;
	int		count_op;
	t_node	*current;

	len = list_length(head_a) / 2;
	while (list_length(head_b) < 3)
		ft_push(head_a, head_b);
	count_op += 3;
	count_op += ft_rev_sort_3(head_b);
	while (head_a->first != NULL)
	{
		// push chaque element dans B (qui est trié Descending) en checkant rot ou rev_rot
		// à l'aide des fonctions en haut
	}
}