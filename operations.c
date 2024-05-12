/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:54:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/11 23:33:57 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *origin)
{
	int	temp;

	if (!origin || !origin->next)
		return ;
	temp = origin->value;
	origin->value = (origin->next)->value;
	(origin->next)->value = temp;
	write(1, "swap occured !", 14);
}

