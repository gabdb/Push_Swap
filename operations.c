/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:54:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/15 16:41:43 by gnyssens         ###   ########.fr       */
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

void	ft_double_swap(t_node *head_a, t_node *head_b)
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
	if (src->first != NULL)
		src->first->previous = src->last; //boucler la boucle: nouveau 1e pointe vers dernier
	//ici en haut, si yavait que 2 noeuds, previous pointerai vers lui-meme
	if (src->first->next == temp)
		src->first->next = src->first; // si cest le seul noeud restant (2 à l'origine), son 'next' pointera vers lui meme
	// QUE FAIRE QUAND IL RESTE 1 SEUL NOEUD ???
}
