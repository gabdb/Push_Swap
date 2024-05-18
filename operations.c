/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:54:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/18 17:09:45 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_head *origin)
{
	int		temp;
	t_node	*current;

	if (!origin || !origin->first || !origin->first->next)
		return ;
	current = origin->first;
	temp = current->value;
	current->value = current->next->value;
	current->next->value = temp;
}

void	ft_push(t_head *src, t_head *dest)
{
	t_node	*save;

	if (!src || !src->first || !dest)
	{
		printf("rien à push... stack vide !!!\n"); //évidemment supp cette merde
		return ;
	}
	save = src->first; // sauver address noeud qui va bouger
	src->first = src->first->next; // tête pointe mnt vers 2e noeud (futur 1e)
	if (src->first == save && src->last == save) // enft ca devrait doffice etre '&&'
	{
		src->first = NULL; // ici cest si le stack est nouvellement vide
		src->last = NULL;
	}
	else
	{
		src->first->previous = src->last; //boucler la boucle: nouveau 1e pointe vers dernier
		src->last->next = src->first;
	}
	if (dest->first == NULL) //sous-traité pour gagner de l'espace
		handle_empty_case(dest, save);
	else
		handle_not_empty(dest, save);
}

void	ft_rotate(t_head *origin)
{
	t_node	*current;
	int		temp1; //bcp plus simple de changer les int plutôt que TOUS les pointers
	int		temp2;

	if (!origin || !origin->first || origin->last == origin->first)
		return ;
	current = origin->last;
	temp1 = current->value;
	current->value = origin->first->value;
	while (current != origin->first)
	{
		current = current->previous;
		temp2 = current->value;
		current->value = temp1;
		temp1 = temp2;
	}
}

void	ft_rev_rotate(t_head *origin)
{
	t_node	*current;
	int		save;

	if (!origin || !origin->first || origin->last == origin->first)
		return ;
	save = origin->last->value;
	current = origin->last;
	while (current != origin->first)
	{
		current->value = current->previous->value;
		current = current->previous;
	}
	current->value = save;
}
