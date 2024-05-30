/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_chosen_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:50:43 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 17:31:15 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_small(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	check_rev_cost(t_head *src, t_head *dest, int value, int index)
{
	int	result;

	result = cost_rev_rotate(value, dest) + list_length(src) - index
		- ft_small(cost_rev_rotate(value, dest), list_length(src) - index);
	return (result);
}

int	check_cost(t_head *src, t_head *dest, int value, int index)
{
	int	result;

	result = cost_rotate(value, dest) + index
		- ft_small(cost_rotate(value, dest), index);
	return (result);
}
