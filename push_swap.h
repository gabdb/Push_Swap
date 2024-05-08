/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:48:24 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/09 01:02:08 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_node
{
	int				value;
	struct s_node	*previous;
	struct s_node	*next;	
}			t_node;

long	my_atoi(char *str);
int		my_strcmp(char *s1, char *s2);
t_node	*new_node(int nbr, t_node *vorige, t_node *volgende);
void	create_linked_list(int count, char **list, t_node *origin);