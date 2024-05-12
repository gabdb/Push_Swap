/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:51:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/11 23:31:16 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_node *origin)
{
	t_node	*current;
	t_node	*volgende;

	if (!origin)
		return ;
	current = origin->next;
	free(origin);
	while (current != NULL && current != origin)
	{
		volgende = current->next;
		free(current);
		current = volgende;
	}
}

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

void	create_stack_a(int count, char **list, t_node *origin)
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
		{
			free_all(origin);
			return ;
		}
		temp_prev->next = current;
		temp_prev = current;
		i++;
	}
	current->next = origin;
	origin->previous = current;
}
