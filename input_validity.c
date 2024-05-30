/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:34:28 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/30 17:37:52 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (!list[1][i + 1])
				return (NULL);
			else if (list[1][i + 1] >= '0' && list[1][i + 1] <= '9')
				i++;
			else
				return (NULL);
		}
		else
			return (NULL);
	}
	new_list = ft_split(list[1], ' ');
	if (!new_list)
		return (NULL);
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
