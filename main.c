/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:29:17 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/31 13:34:10 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_head *head, int ac, char **av)
{
	t_node	*current;

	current = head->first->next;
	while (current != head->first)
	{
		if (current->value < current->previous->value)
			return (0);
		current = current->next;
	}
	if (ac == 2)
		free_split(av, (size_t)ac);
	return (1);
}

void	handle_short_list(t_head *head_a, t_head *head_b, int ac, char **av)
{
	if (list_length(head_a) == 2)
	{
		if (head_a->first->value > head_a->last->value)
			ft_swap(head_a, 'a');
	}
	else
		ft_sort_3(head_a, 'a');
	free_all(head_a);
	free_all(head_b);
	if (ac == 2)
		free_split(av, (size_t)ac);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_head	*head_a;
	t_head	*head_b;

	if (ac == 1)
		return (0);
	if (ac == 2)
		av = all_in_one(av);
	if (!av)
		return (write(1,"Error\n", 6), 0);
	ac = words_in_split(av);
	if (valid_input(ac, av) == 0)
		return (write(1,"Error\n", 6), 0);
	else if (check_doubles(ac, av) == 0)
		return (write(1,"Error\n", 6), 0);
	head_a = init_head();
	head_b = init_head();
	create_stack_a(ac, av, head_a);
	if (is_sorted(head_a, ac, av))
		return (0);
	if (list_length(head_a) <= 3)
		handle_short_list(head_a, head_b, ac, av);
	push_swap(head_a, head_b);
	if (ac == 2)
		free_split(av, (size_t)ac);
	free_all(head_a);
	free_all(head_b);
	return (0);
}
