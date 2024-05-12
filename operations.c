/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:54:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/13 00:24:14 by gnyssens         ###   ########.fr       */
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

void	ft_double_swap(t_node *head_a, t_node *head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
	write(1, "double swap !", 13);
}

void	ft_push(t_node *src, t_node *dest) //probleme avec 'origin', envisager **dptr
{
	
	t_node	*temp;
	int		int_temp;

	if (!dest)
		return ;
	temp =  src->next; //sauver address 2e noeud de stack 'b'
	src->previous->next = temp; //faire pointer dernier noeud de 'b' vers nouveau premier noeud
	temp = src->previous; //sauver address dernier noeud
	src->next->previous = temp; //nouveau premier noeud pointe vers dernier
	
	temp = dest->previous; //sauver address dernier de 'a'
	dest->previous = src; //nouveau 2e de 'a' pointe mnt sur src
	temp->next = src; //dernier de 'a' pointe mnt sur src
	
	src->next = dest;
	src->previous = temp;
}