/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:29:17 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/16 16:10:50 by gnyssens         ###   ########.fr       */
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
		list = all_in_one(av);
	if (!list)
		return (printf("Error: invalid input !\n"), 0);
	count = words_in_split(list);

	if (valid_input(count, list) == 0)
		return (printf("Error: invalid input !\n"), 0);
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
	t_head	*origin_a;

	origin_a = init_head();
	create_stack_a(ac, av, origin_a);
	current = origin_a->first;
	printf("t_head, donc structure mère: %p\n", origin_a);
	printf("address 'first': %p\n", origin_a->first);
	printf("address 'last': %p\n\n", origin_a->last);
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

void print_stack_details(t_head *origin)
{
    if (origin == NULL || origin->first == NULL) {
        printf("Stack is empty or not initialized.\n");
        return;
    }

    t_node *current = origin->first;
    int i = 0;
    do {
        printf("%d'th node : %p\n", i+1, current);
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
        i++;
    } while (current != origin->first);
}
/*
int main(int ac, char **av)
{
    if (ac < 2) {
        printf("Usage: %s <number1> <number2> ... <numberN>\n", av[0]);
        return 1;
    }
    if (valid_input(ac, av) == 0)
        return (printf("Error: invalid input!\n"));
    else if (check_doubles(ac, av) == 0)
        return (printf("Error: duplicates!\n"), 0);
    else
        printf("Valid input for push_swap!\n\n");

    t_head *origin_a = init_head();
    t_head *origin_b = init_head(); // Initialize stack b, initially empty

    create_stack_a(ac, av, origin_a);
    printf("Stack A initialization complete:\n");
    print_stack_details(origin_a);

    // Let's try to push the first element from A to B
    if (origin_a->first != NULL) {
        printf("Pushing top node from Stack A to Stack B:\n");
        ft_push(origin_a, origin_b);
        printf("Stack A after one push:\n");
        print_stack_details(origin_a);
        printf("Stack B after one push:\n");
        print_stack_details(origin_b);

        // Optionally, push more nodes or perform other operations
        // while (origin_a->first != NULL)
        //     ft_push(origin_a, origin_b);
    }

    // Clean up
    free_all(origin_a);
    free_all(origin_b);

    return 0;
}
*/