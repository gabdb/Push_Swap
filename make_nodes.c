/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:51:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/09 01:17:55 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int nbr, t_node *vorige, t_node *volgende)
{
	t_node	*result;

	result = (t_node *)malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->value = nbr;
	result->previous = vorige;
	result->next = volgende;
	return (result);
}

void	create_linked_list(int count, char **list, t_node *origin)
{
	t_node	*current;
	t_node	*temp_prev;
	int		nbr;
	int		i;

	temp_prev = origin;
	i = 2;
	while (i < count)
	{
		nbr = (int) my_atoi(list[i]);
		current = new_node(nbr, temp_prev, NULL);
		if (!current)
			return ; //ici faudra tout free au besoin !
		temp_prev->next = current;
		temp_prev = current;
		i++;
	}
	current->next = origin;
	origin->previous = current;
}
