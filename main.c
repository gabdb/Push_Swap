/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:29:17 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/03 17:06:51 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split_exit(int ac, char **av)
{
	write(2, "Error\n", 6);
	if (ac == 2)
		free_split(av, ac + 1);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_head *head)
{
	t_node	*current;

	current = head->first->next;
	while (current != head->first)
	{
		if (current->value < current->previous->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	handle_short_list(t_head *head_a)
{
	if (list_length(head_a) == 2)
	{
		if (head_a->first->value > head_a->last->value)
			ft_swap(head_a, 'a');
	}
	else
		ft_sort_3(head_a, 'a');
}

int	main(int ac, char **av)
{
	t_head	*head_a;
	t_head	*head_b;
	int		words;

	if (ac == 1)
		return (0);
	if (ac == 2)
		av = all_in_one(av);
	words = words_in_split(av);
	if (valid_input(words, av) == 0 || check_doubles(words, av) == 0)
		free_split_exit(words, av);
	head_a = init_head();
	head_b = init_head();
	create_stack_a(words, av, head_a);
	if (ac == 2)
		free_split(av, (size_t)words + 1);
	if (is_sorted(head_a))
		free_stacks_exit(head_a, head_b);
	if (list_length(head_a) <= 3)
		handle_short_list(head_a);
	else
		push_swap(head_a, head_b);
	free_stacks_exit(head_a, head_b);
	return (0);
}
