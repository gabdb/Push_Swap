/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:54:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/17 15:28:59 by gnyssens         ###   ########.fr       */
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

void	ft_double_swap(t_head *head_a, t_head *head_b)
{
	ft_swap(head_a);
	ft_swap(head_b);
	write(1, "double swap !", 13);
}

void	ft_push(t_head *src, t_head *dest)
{
	t_node	*temp;

	if (!src || !src->first || !dest)
		return ;
	temp = src->first; // sauver address noeud qui va bouger
	src->first = src->first->next; // tête pointe mnt vers 2e noeud (futur 1e)
	if (src->first == temp && src->last == temp) // enft ca devrait doffice etre '&&'
	{
		src->first = NULL; // ici cest si le stack est nouvellement vide
		src->last = NULL;
	}
	else
	{
		src->first->previous = src->last; //boucler la boucle: nouveau 1e pointe vers dernier
		src->last->next = src->first;
	}
	dest->first = temp; //rattacher le nouveau au début du 2e stack
	if (dest->last == NULL) // == NULL ça veut dire que stack était vide
		dest->last = dest->first;
	dest->first->previous = dest->last; //prev du nouveau 1e pointe vers dernier noeud du stack
	dest->first->next = dest->last->next; //next du nouveau 1e pointe vers ancien 1e
	if (dest->first->previous == dest->first) // si cst le cas, dest->first->previous == lui-meme
		dest->first->next = dest->first; //régler le pb: 'next' du nouveau 1e pointe vers lui-meme au lieu de -> l'ancien 'next' qui est mnt le 1e de src
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
