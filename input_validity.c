/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:34:28 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/03 13:22:55 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

char	**all_in_one(char **list)
{
	char	**new_list;
	int		i;

	i = 0;
	while (list[1][i] != '\0')
	{
		if (list[1][i] == ' ' || (list[1][i] >= '0' && list[1][i] <= '9'))
			i++;
		else if (list[1][i] == '-')
		{
			if (list[1][i + 1] >= '0' && list[1][i + 1] <= '9')
				i++;
			else
				error_and_exit();
		}
		else
			error_and_exit();
	}
	list[1] = ft_strjoin("push_swap ", list[1]);
	new_list = ft_split(list[1], ' ');
	free(list[1]);
	if (!new_list)
		exit(EXIT_FAILURE);
	return (new_list);
}

int	words_in_split(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
		i++;
	return (i);
}

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

int	check_doubles(int count, char **list)
{
	int	i;
	int	j;

	i = 1;
	while (i + 1 < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (my_atoi(list[i]) == my_atoi(list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
