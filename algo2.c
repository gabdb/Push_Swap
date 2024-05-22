/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:25:19 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/22 16:25:01 by gnyssens         ###   ########.fr       */
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
	return (index);
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
	if (current->value < min)
		min = current->value;
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
	if (current->value > max)
		max = current->value;
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
	return (cost);
}

int	cost_rev_rotate(int value, t_head *head)
{
	int	cost;

	cost = 0;
	if (value > ft_max(head) || value < ft_min(head))
		cost = list_length(head) - index_max(head);
	else
		cost = list_length(head) - index_bf(value, head);
	return (cost);
}

int	algo_nul(t_head *head_a, t_head *head_b)
{
	int		cost;
	int		count_op;
	int		value;
	int		i;

	count_op = 0;
	while (list_length(head_b) < 3)
		ft_push(head_a, head_b);
	count_op += 3;
	count_op += ft_rev_sort_3(head_b);
	while (head_a->first != NULL)
	{
		//print_stack(head_b);
		i = index_chosen_one(head_a, head_b);
		if (i < (list_length(head_a) / 2))
		{
			count_op += i;
			while (i-- > 0)
				ft_rotate(head_a);
		}
		else
		{
			count_op += list_length(head_a) - i;
			while (i++ < list_length(head_a))
				ft_rev_rotate(head_a);
		}
		value = head_a->first->value;
		if (cost_rotate(value, head_b) < cost_rev_rotate(value, head_b))
		{
			cost = cost_rotate(value, head_b);
			while (cost-- > 0)
			{
				ft_rotate(head_b);
				count_op++;	
			}
		}
		else
		{
			cost = cost_rev_rotate(value, head_b);
			while (cost-- > 0)
			{
				ft_rev_rotate(head_b);
				count_op++;	
			}
		}
		ft_push(head_a, head_b);
		count_op++;
	}
	max_on_top(head_b, &count_op);
	while (head_b->first != NULL)
	{
		ft_push(head_b, head_a);
		count_op++;
	}
	return (count_op);
}

void	max_on_top(t_head *head, int *count)
{
	int	index;
	int	len;

	len = list_length(head);
	index = index_max(head);
	if (index < (len / 2))
	{
		while (index-- > 0)
		{
			ft_rotate(head);
			(*count)++;
		}
	}
	else
	{
		while (index++ < len)
		{
			ft_rev_rotate(head);
			(*count)++;
		}
	}
}
int	index_chosen_one(t_head *head_a, t_head *head_b)
{
	t_node	*current;
	int		best_index;
	int		index;
	int		cost;
	int		len;

	len = list_length(head_a);
	best_index = 0;
	index = 0;
	cost = cost_rotate(head_a->first->value, head_b) + index;
	if (cost_rev_rotate(head_a->first->value, head_b) + len - index < cost)
		cost = cost_rev_rotate(head_a->first->value, head_b) + len - index;
	current = head_a->first->next;
	while (current != head_a->first)
	{
		index++;
		if (cost_rotate(current->value, head_b) + index < cost)
		{
			cost = cost_rotate(current->value, head_b) + index;
			best_index = index;
		}
		if (cost_rev_rotate(current->value, head_b) + len - index < cost)
		{
			cost = cost_rev_rotate(current->value, head_b) + len - index;
			best_index = index;
		}
		current = current->next;
	}
	return (best_index);
}
