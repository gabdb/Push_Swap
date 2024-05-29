/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:29:17 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/29 14:52:55 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	/*
	else
		printf("valid input for push_swap !\n");
	printf("#of integers: %d\n\n", count - 1);
	*/

	t_head	*head_A = init_head();
	t_head	*head_B = init_head();
	create_stack_a(count, list, head_A);
	push_swap(head_A, head_B);
	//print_stack(head_A);

	free_all(head_A);
	free_all(head_B);

	return 0;
}
