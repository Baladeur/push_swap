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

int				add_to_stack(t_stack **st, int nb);

void			destroy_stack(t_stack **st);

t_stack			*dupe_stack(t_stack *src);

int				fill_stack(int ac, char **av, t_stack **a);

void			print_stack(t_stack *st);

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

char			**bubble_sort(t_stack *orig);

/*char			**selection_sort(t_stack *orig);

char			**insertion_sort(t_stack *orig);

char			**quick_sort(t_stack *orig);

char			**gnome_sort(t_stack *orig);

char			**brute_sort(t_stack *orig);*/

#endif