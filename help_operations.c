/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:05:20 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 17:45:31 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_empty_case(t_head *dest, t_node *save)
{
	dest->first = save;
	dest->last = save;
	save->previous = save;
	save->next = save;
}

void	handle_not_empty(t_head *dest, t_node *save)
{
	save->next = dest->first;
	save->previous = dest->last;
	dest->first->previous = save;
	dest->last->next = save;
	dest->first = save;
}

void	ft_double_rotate(t_head *head_a, t_head *head_b)
{
	ft_rotate(head_a, '\0');
	ft_rotate(head_b, '\0');
	write(1, "rr\n", 3);
}

void	ft_double_rev_rotate(t_head *head_a, t_head *head_b)
{
	ft_rev_rotate(head_a, '\0');
	ft_rev_rotate(head_b, '\0');
	write(1, "rrr\n", 4);
}
