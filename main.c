/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:29:17 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/09 01:26:15 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_input(int count, char **list)
{
	int		i;
	int		j;
	long	test;

	if (count <= 1)
		return (0);
	i = 0;
	while (++i < count)
	{
		j = -1;
		while (list[i][++j] != '\0')
		{
			if (list[i][j] == '-' && 0 == j)
				j++;
			if (list[i][j] == '\0')
				return (0);
			if (list[i][j] < '0' || list[i][j] > '9')
				return (0);
		}
		test = my_atoi(list[i]);
		if (test < -2147483648 || test > 2147483647)
			return (0);
	}
	return (1);
}

int check_doubles(int count, char **list)
{
	int	i;
	int	j;

	i = 1;
	while (i + 1 < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (my_strcmp(list[i], list[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
	create_linked_list(ac, av, origin);
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