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
# include "../libft/libft.h"

typedef struct	s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_part
{
	int		id;
	int		op;
	int		ed;
}				t_part;

/*
** stack tools
*/

int				add_to_stack(t_stack **st, int nb, int boolean);

void			destroy_stack(t_stack **st);

void			dupe_stack(t_stack *src, t_stack **dest, int b);

int				fill_stack(int ac, char **av, t_stack **a);

int				stack_size(t_stack *st);

void			results_cleaner(t_stack **res, t_stack *orig, int i);

void			safer_cleaner(t_stack **res, t_stack **a, int sz, t_stack *o);

int				secure_empty(t_stack **res, t_stack **a, t_stack **b, int i);

int				rota_cleaner(t_stack **res, t_stack **a, t_stack **b, int i);

int				exec_mv(t_stack **a, t_stack **b, int mv);

t_stack			*get_at(t_stack *src, int i);

void			set_at(t_stack *src, int i, int v);

void			destroy_at(t_stack **st, int i);

void			results_checker(t_stack **results, t_stack *orig);

int				moveset_checker(t_stack *moveset, t_stack *orig);

/*
** part tools
*/

int				init_part(t_part **part, int size, int id);

int				is_part_sort(t_part *part, t_stack *a, t_stack *b);

int				part_median(t_part *part, t_stack *st);

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

int				is_rev_sort(t_stack *st);

/*
** sorting algorithms
*/

t_stack			*bubble_sort(t_stack *orig);

t_stack			*gnome_sort(t_stack *orig);

t_stack			*selection_sort(t_stack *orig);

t_stack			*insertion_sort(t_stack *orig);

t_stack			*quicksort(t_stack *orig);

#endif
