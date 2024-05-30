/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:41:07 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 17:37:22 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_and_len(t_head *head_a, t_head *head_b, char q, int *len)
{
	ft_push(head_a, head_b, q);
	(*len)--;
}

void	early_push(t_head *head_a, t_head *head_b)
{
	double	total_len;
	int		len;
	double	hack;

	total_len = list_length(head_a);
	len = total_len;
	while (len > 150)
	{
		if ((double)head_a->first->value <= ft_average(head_a) * 0.85)
			push_and_len(head_a, head_b, 'b', &len);
		else
			ft_rotate(head_a, 'a');
	}
	while (list_length(head_a) > 3)
	{
		if ((double)head_a->first->value < ft_average(head_a))
			ft_push(head_a, head_b, 'b');
		else
			ft_rotate(head_a, 'a');
	}
	ft_sort_3(head_a, 'a');
}

void	handle_up(t_head *head_a, t_head *head_b, int i, int cost)
{
	while (i > 0 && cost > 0)
	{
		ft_double_rotate(head_b, head_a);
		i--;
		cost--;
	}
	while (i-- > 0)
		ft_rotate(head_b, 'b');
	while (cost-- > 0)
		ft_rotate(head_a, 'a');
}

void	handle_down(t_head *head_a, t_head *head_b, int i, int cost)
{
	while (i < list_length(head_b) && cost > 0)
	{
		ft_double_rev_rotate(head_b, head_a);
		i++;
		cost--;
	}
	while (i++ < list_length(head_b))
		ft_rev_rotate(head_b, 'b');
	while (cost-- > 0)
		ft_rev_rotate(head_a, 'a');
}
