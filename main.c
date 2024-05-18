/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:29:17 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/18 02:08:02 by gnyssens         ###   ########.fr       */
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
	
	t_head	*head_A = init_head();
	t_head	*head_B = init_head();
	create_stack_a(count, list, head_A);
	int aantal_op = algo_merde(head_A, head_B);
	t_node	*current = head_A->first->next;
	printf("%d\n", head_A->first->value);
	while (current != head_A->first)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("\n aantal allowed operations: %d", aantal_op);

	free_all(head_A);
	free_all(head_B);

	return 0;
}
*/

/*
int main(int ac, char **av)
{
    if (1 == ac)
        return (printf("empty argument !\n"), 0);
	else if (valid_input(ac, av) == 0)
		return (printf("Error: non-digit input !\n"));
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

    ft_rev_rotate(origin_a);
    printf("AFTER REV_ROTATE: \n\n");

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

/*
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
*/
/*
int main(int ac, char **av)
{
    if (valid_input(ac, av) == 0)
        return (printf("Error: invalid input!\n"));
    else if (check_doubles(ac, av) == 0)
        return (printf("Error: duplicates!\n"), 0);
    else
        printf("Valid input for push_swap!\n\n");

    t_head *origin_a = init_head();
    t_head *origin_b = init_head();

    create_stack_a(ac, av, origin_a);
    //print_stack_details(origin_a);
	for (int x = 0; x < 5; x++)
	{
        printf("Stack A:\n");
        print_stack(origin_a);
        printf("Stack B:\n");
        print_stack(origin_b);
    	printf("ft_push arrive !\n");
    	ft_push(origin_a, origin_b);
	}

    // Clean up
    free_all(origin_a);
    free_all(origin_b);

    return 0;
}
*/