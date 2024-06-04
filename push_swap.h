/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:48:24 by gnyssens          #+#    #+#             */
/*   Updated: 2024/06/03 13:31:38 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_getal
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	words;
	char	**final;
}				t_getal;

typedef struct s_node
{
	int				value;
	struct s_node	*previous;
	struct s_node	*next;	
}			t_node;

typedef struct s_head
{
	t_node	*first;
	t_node	*last;
}			t_head;

typedef struct s_v
{
	t_node	*current;
	int		best_index;
	int		index;
	int		cost;
}			t_v;

// VALIDITY PROTOTYPES
char	**all_in_one(char **list);
int		valid_input(int count, char **list);
int		check_doubles(int count, char **list);
int		words_in_split(char **list);
void	error_and_exit(void);

// NODES PROTOYPES
void	free_stack(t_head *origin);
t_node	*new_node(int nbr, t_node *vorige, t_node *volgende);
void	create_stack_a(int count, char **list, t_head *origin);
t_head	*init_head(void);

// OPERATIONS
void	ft_swap(t_head *origin, char q);
void	ft_push(t_head *src, t_head *dest, char q);
void	ft_rotate(t_head *origin, char q);
void	ft_rev_rotate(t_head *origin, char q);

// HELP OPERATIONS
void	handle_empty_case(t_head *dest, t_node *save);
void	handle_not_empty(t_head *dest, t_node *save);
void	ft_double_swap(t_head *head_a, t_head *head_b);
void	ft_double_rotate(t_head *head_a, t_head *head_b);
void	ft_double_rev_rotate(t_head *head_a, t_head *head_b);

// UTILS
long	my_atoi(char *str);
int		value_at_index(t_head *head, int index);
double	ft_average(t_head *head);
void	min_on_top(t_head *head, char q);
int		ft_min(t_head *head);

// SPECIAL SPLIT (faudra enlever et rajouter libft)
char	**ft_split(char const *s, char c);
void	free_split(char **dptr, size_t x);

//ALGO MITEUX (plûtot un test, probablement à supprimer)
int		list_length(t_head *origin);
int		index_min(t_head *origin);
int		index_max(t_head *origin);
int		ft_rev_sort_3(t_head *head);
void	ft_sort_3(t_head *head, char q);

// ALGO 2 fichier
void	push_swap(t_head *head_a, t_head *head_b);
int		index_bf(int value, t_head *head);
int		ft_min(t_head *head);
int		ft_rev_sort_3(t_head *head);
int		cost_rotate(int value, t_head *head);
int		cost_rev_rotate(int value, t_head *head);
int		index_chosen_one(t_head *src, t_head *dest, char *u_or_d);

// UTILS 2
int		ft_min(t_head *head);
int		ft_max(t_head *head);
void	free_stacks_exit(t_head *head_a, t_head *head_b);

// HELP CHOSEN INDEX
int		ft_small(int a, int b);
int		check_rev_cost(t_head *src, t_head *dest, int value, int index);
int		check_cost(t_head *src, t_head *dest, int value, int index);

//HELP ALGO
void	early_push(t_head *head_a, t_head *head_b);
void	push_and_len(t_head *head_a, t_head *head_b, char q, int *len);
void	handle_up(t_head *head_a, t_head *head_b, int i, int cost);
void	handle_down(t_head *head_a, t_head *head_b, int i, int cost);

//FIFTY HACK
int		find_min_list(int *list, t_head *head);
void	fill_list(int *list, t_head *head);
int		is_smallest_50(int value, t_head *head);

//STRJOIN
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *src);

#endif
