/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:25:19 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/24 15:59:10 by gnyssens         ###   ########.fr       */
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
	char	u_or_d[1];

	count_op = 0;
	while (list_length(head_a) > 3)
	{
		if (head_a->first->value < ft_average(head_a))
			ft_push(head_a, head_b);
		else
			ft_rotate(head_a);
		count_op++;
	}
	while (head_b->first != NULL)
	{
		i = index_chosen_one(head_b, head_a, u_or_d);
		value = value_at_index(head_b, i);
		cost = cost_rotate(value, head_a);
		if (*u_or_d == 'd')
			cost = cost_rev_rotate(value, head_a);
		if ('u' == *u_or_d)
		{
			while (i > 0 && cost > 0)
			{
				ft_double_rotate(head_b, head_a);
				count_op++;
				i--;
				cost--;
			}
			while (i-- > 0)
			{
				ft_rotate(head_b);
				count_op++;
			}
			while (cost-- > 0)
			{
				ft_rotate(head_a);
				count_op++;
			}
		}
		else
		{
			while (i < list_length(head_b) && cost > 0)
			{
				ft_double_rev_rotate(head_b, head_a);
				count_op++;
				i++;
				cost--;
			}
			while (i++ < list_length(head_b))
			{
				ft_rev_rotate(head_b);
				count_op++;
			}
			while (cost-- > 0)
			{
				ft_rev_rotate(head_a);
				count_op++;
			}
		}
		ft_push(head_b, head_a);
		count_op++;
	}
	max_on_top(head_a, &count_op);
	return (count_op);
}

int	index_chosen_one(t_head *head_a, t_head *head_b, char *u_or_d)
{
	t_node	*current;
	int		best_index;
	int		index;
	int		cost;
	int		len;

	len = list_length(head_a);
	best_index = 0;
	index = 0;
	cost = cost_rotate(head_a->first->value, head_b) + index - ft_small(cost_rotate(head_a->first->value, head_b), index);
	*u_or_d = 'u';
	if (cost_rev_rotate(head_a->first->value, head_b) + len - index - ft_small(cost_rev_rotate(head_a->first->value, head_b), len - index) < cost)
	{
		cost = cost_rev_rotate(head_a->first->value, head_b) + len - index - ft_small(cost_rev_rotate(head_a->first->value, head_b), len - index);
		*u_or_d = 'd';
	}
	current = head_a->first->next;
	while (current != head_a->first)
	{
		index++;
		if ((cost_rotate(current->value, head_b) + index - ft_small(cost_rotate(current->value, head_b), index)) < cost)
		{
			cost = cost_rotate(current->value, head_b) + index - ft_small(cost_rotate(current->value, head_b), index);
			best_index = index;
			*u_or_d = 'u';
		}
		if ((cost_rev_rotate(current->value, head_b) + len - index - ft_small(cost_rev_rotate(current->value, head_b), len - index)) < cost)
		{
			cost = cost_rev_rotate(current->value, head_b) + len - index - ft_small(cost_rev_rotate(current->value, head_b), len - index);
			best_index = index;
			*u_or_d = 'd';
		}
		current = current->next;
	}
	return (best_index);
}
