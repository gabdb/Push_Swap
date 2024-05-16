/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnyssens <gnyssens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:48:24 by gnyssens          #+#    #+#             */
/*   Updated: 2024/05/17 00:32:22 by gnyssens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



// VALIDITY PROTOTYPES
char	**all_in_one(char **list);
int		valid_input(int count, char **list);
int		check_doubles(int count, char **list);
int		words_in_split(char **list);

// NODES PROTOYPES
void	free_all(t_head *origin);
t_node	*new_node(int nbr, t_node *vorige, t_node *volgende);
void	create_stack_a(int count, char **list, t_head *origin);
t_head	*init_head(void);

// OPERATIONS
void	ft_swap(t_head *origin);
void	ft_double_swap(t_head *head_a, t_head *head_b);
void	ft_push(t_head *src, t_head *dest);
void	ft_rotate(t_head *origin);
void	ft_rev_rotate(t_head *origin);

// UTILS PROTOTYPES
long	my_atoi(char *str);
int		my_strcmp(char *s1, char *s2);

// SPECIAL SPLIT (faudra enlever et rajouter libft)
char	**ft_split(char const *s, char c);
