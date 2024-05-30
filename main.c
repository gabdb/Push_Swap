/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:29:17 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 18:02:47 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**list;
	int		count;
	t_head	*head_a;
	t_head	*head_b;

	count = ac;
	list = av;
	if (ac == 2)
		list = all_in_one(av);
	if (!list)
		return (write(1,"Error\n", 6), 0);
	count = words_in_split(list);
	if (valid_input(count, list) == 0)
		return (write(1,"Error\n", 6), 0);
	else if (check_doubles(count, list) == 0)
		return (write(1,"Error\n", 6), 0);
	head_a = init_head();
	head_b = init_head();
	create_stack_a(count, list, head_a);
	push_swap(head_a, head_b);
	free_all(head_a);
	free_all(head_b);
	return (0);
}
