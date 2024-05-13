/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:51:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/13 23:46:00 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*init_head(void)
{
	t_head	*result;

	result = (t_head *)malloc(sizeof(t_head));
	if (!result)
		return (NULL);
	result->first = NULL;
	result->last = NULL;
	return (result);
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

void	create_stack_a(int count, char **list, t_head *origin)
{
	t_node	*current;
	t_node	*temp_prev;
	int		nbr;
	int		i;

	temp_prev = NULL;
	i = 0;
	while (++i < count)
	{
		nbr = (int) my_atoi(list[i]);
		current = new_node(nbr, temp_prev, NULL);
		if (!current)
		{
			free_all(origin);
			return ;
		}
		if (i == 1)
			origin->first = current;
		else
			temp_prev->next = current;
		temp_prev = current;
	}
	current->next = origin->first;
	origin->first->previous = current;
	origin->last = current;
}

void	free_all(t_head *origin)
{
	t_node	*current;
	t_node	*volgende;

	if (!origin)
		return ;
	current = origin->first;
	while (current != NULL && current != origin->first)
	{
		volgende = current->next;
		free(current);
		current = volgende;
	}
	free(origin);
}
