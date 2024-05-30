/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:25:19 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 17:36:02 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_bf(int value, t_head *head)
{
	int		index;
	t_node	*current;

	current = head->first;
	index = 0;
	while (current != head->last)
	{
		if (value > current->previous->value && value < current->value)
			return (index);
		index++;
		current = current->next;
	}
	return (index);
}

int	cost_rotate(int value, t_head *head)
{
	int	cost;

	cost = 0;
	if (value > ft_max(head) || value < ft_min(head))
		cost = index_min(head);
	else
		cost = index_bf(value, head);
	return (cost);
}

int	cost_rev_rotate(int value, t_head *head)
{
	int	cost;

	cost = 0;
	if (value > ft_max(head) || value < ft_min(head))
		cost = list_length(head) - index_min(head);
	else
		cost = list_length(head) - index_bf(value, head);
	return (cost);
}

void	push_swap(t_head *head_a, t_head *head_b)
{
	int		cost;
	int		value;
	int		i;
	char	u_or_d[1];

	early_push(head_a, head_b);
	while (head_b->first != NULL)
	{
		i = index_chosen_one(head_b, head_a, u_or_d);
		value = value_at_index(head_b, i);
		cost = cost_rotate(value, head_a);
		if (*u_or_d == 'd')
			cost = cost_rev_rotate(value, head_a);
		if ('u' == *u_or_d)
			handle_up(head_a, head_b, i, cost);
		else
			handle_down(head_a, head_b, i, cost);
		ft_push(head_b, head_a, 'a');
	}
	min_on_top(head_a, 'a');
}

int	index_chosen_one(t_head *src, t_head *dest, char *u_or_d)
{
	t_v	v;

	v.best_index = 0;
	v.index = 0;
	v.cost = cost_rotate(src->first->value, dest);
	*u_or_d = 'u';
	v.current = src->first;
	while (v.current != src->first || v.index == 0)
	{
		if (check_cost(src, dest, v.current->value, v.index) < v.cost)
		{
			v.cost = check_cost(src, dest, v.current->value, v.index);
			v.best_index = v.index;
			*u_or_d = 'u';
		}
		if (check_rev_cost(src, dest, v.current->value, v.index) < v.cost)
		{
			v.cost = check_rev_cost(src, dest, v.current->value, v.index);
			v.best_index = v.index;
			*u_or_d = 'd';
		}
		v.current = v.current->next;
		v.index++;
	}
	return (v.best_index);
}
