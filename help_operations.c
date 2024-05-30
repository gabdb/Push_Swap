/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:05:20 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 12:36:26 by gnyssens         ###   ########.fr       */
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
