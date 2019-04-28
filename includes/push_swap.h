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

/*
** bruteforce psuh_swap init
*/

void 			brute(t_stack *moveset, t_stack *a, t_stack *bcmp);

/*
** stack tools
*/

int				add_stack(t_stack **st, int nb);

void			destroy_stack(t_stack **st);

int				is_sort(t_stack *st);

int				fill_stack(int ac, char **av, t_stack **a);

void			print_stack(t_stack *st);

/*
** stack moveset
*/

void			swap(t_stack *st);

void			push(t_stack **src, t_stack **dst);

void			rotate(t_stack **st);

void			rev_rotate(t_stack **st);

/*
** stack sorter
*/

void			sswap(t_stack *a, t_stack *b);

void			rrotate(t_stack **a, t_stack **b);

void			rev_rrotate(t_stack **a, t_stack **b);

int				sort_stack(t_stack **a, t_stack **b);

#endif
