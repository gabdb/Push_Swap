/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:54:58 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/16 23:21:38 by gnyssens         ###   ########.fr       */
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
