/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:51:53 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/25 17:59:37 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atoi(char *str)
{
	long	sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= (-1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str++ - '0';
		if (res < -2147483648)
			return (-2147483649);
		if (res > 2147483647)
			return (2147483649);
	}
	return (sign * res);
}

int	my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

void print_stacks(t_head *head_a, t_head *head_b) {
    t_node *current_a = (head_a->first) ? head_a->first : NULL;
    t_node *current_b = (head_b->first) ? head_b->first : NULL;

    bool a_done = (current_a == NULL);
    bool b_done = (current_b == NULL);

    while (!a_done || !b_done) {
        if (!a_done) {
            printf("%d", current_a->value);
            current_a = current_a->next;
            a_done = (current_a == head_a->first);
        } else {
            printf("E");
        }

        printf("     ");

        if (!b_done) {
            printf("%d", current_b->value);
            current_b = current_b->next;
            b_done = (current_b == head_b->first);
        } else {
            printf("E");
        }

        printf("\n");
    }
	//printf("\n");
}

int	ft_small(int a, int b) //promo en utilisant rr / rrr
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	value_at_index(t_head *head, int index)
{
	t_node	*current;
	int		i;

	current = head->first;
	i = 0;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current->value);
}

int	ft_average(t_head *head)
{
	int		count;
	int		length;
	t_node	*current;

	length = list_length(head);
	count = head->first->value;
	current = head->first->next;
	while (current != head->first)
	{
		count += current->value;
		current = current->next;
	}
	return (count / length);
}

void	max_on_top(t_head *head, int *count)
{
	int	index;
	int	len;

	len = list_length(head);
	index = index_max(head);
	if (index < (len / 2))
	{
		while (index-- > 0)
		{
			ft_rotate(head);
			(*count)++;
		}
	}
	else
	{
		while (index++ < len)
		{
			ft_rev_rotate(head);
			(*count)++;
		}
	}
}

void	min_on_top(t_head *head, int *count)
{
	int	index;
	int	len;

	len = list_length(head);
	index = index_min(head);
	if (index <= (len / 2))
	{
		while (index-- > 0)
		{
			ft_rotate(head);
			(*count)++;
		}
	}
	else
	{
		while (index++ < len)
		{
			ft_rev_rotate(head);
			(*count)++;
		}
	}
}
