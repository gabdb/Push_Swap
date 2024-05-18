/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:05:20 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/18 01:05:47 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_swap(t_head *head_a, t_head *head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
	write(1, "double swap !", 13);
}
