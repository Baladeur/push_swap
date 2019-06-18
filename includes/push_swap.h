/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:37:34 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 18:53:48 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

/*
** stack tools
*/

int				add_to_stack(t_stack **st, int nb, int boolean);

void			destroy_stack(t_stack **st);

void			dupe_stack(t_stack *src, t_stack **dest);

int				fill_stack(int ac, char **av, t_stack **a);

void			print_stack(t_stack *st);

t_stack			*get_at(t_stack *src, int i);

int				stack_size(t_stack *st);

void			moveset_cleaner(t_stack **results, t_stack *orig);

/*
** stack moveset
*/

int				swap(t_stack *st);

int				push(t_stack **src, t_stack **dst);

int				rotate(t_stack **st);

int				rev_rotate(t_stack **st);

/*
** stack sorter
*/

int				sort_stack(t_stack **a, t_stack **b);

int				is_sort(t_stack *st);

/*
** sorting algorithms
*/

t_stack			*bubble_sort(t_stack *orig);

t_stack			*gnome_sort(t_stack *orig);

t_stack			*selection_sort(t_stack *orig);

t_stack			*insertion_sort(t_stack *orig);

/*t_stack			*selection_sort(t_stack *orig);

t_stack			*insertion_sort(t_stack *orig);

t_stack			*quick_sort(t_stack *orig);

t_stack			*brute_sort(t_stack *orig);*/

#endif