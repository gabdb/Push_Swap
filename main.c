/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:29:17 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/12 15:22:42 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int main(int ac, char **av)
{
	char	**list;
	int		count;

	count = ac;
	list = av;
	if (ac == 2)
	{
		list = all_in_one(av);
		count = words_in_split(list);
	}

	if (valid_input(count, list) == 0)
		return (printf("Error: invalid input !\n"));
	else if (check_doubles(count, list) == 0)
		return (printf("Error: doublons !\n"), 0);
	else
		printf("valid input for push_swap !\n");

	return 0;
}
*/

/*
int main(int ac, char **av)
{
	if (valid_input(ac, av) == 0)
		return (printf("Error: invalid input !\n"));
	else if (check_doubles(ac, av) == 0)
		return (printf("Error: doublons !\n"), 0);
	else
		printf("valid input for push_swap !\n\n");

	t_node	*current;
	t_node	*origin;
	int		nbr;

	nbr = (int) my_atoi(av[1]);
	origin = new_node(nbr, NULL, NULL);
	create_stack_a(ac, av, origin);
	current = origin;
	for (int i = 1; i < ac; i++)
	{
		printf("%d'th node : %p\n", i, current);
		printf(" ------------------------------- \n");
		printf("|                              |\n");
		printf("| nbr: %d                       |\n", current->value);
		printf("|                              |\n");
		printf("| address prev: %p |\n", current->previous);
		printf("|                              |\n");
		printf("| address next: %p |\n", current->next);
		printf("|                              |\n");
		printf(" ------------------------------- \n\n");
		current = current->next;
	}
	
	return 0;
}
*/