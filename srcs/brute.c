/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:51:21 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/28 16:51:22 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	undo_move(t_stack *move, t_stack **a, t_stack **b)
{
	if (move->value == 0)
		swap(*a);
	else if (move->value == 1)
		swap(*b);
	else if (move->value == 2)
		sswap(*a, *b);
	else if (move->value == 3)
		push(a, b);
	else if (move->value == 4)
		push(b, a);
	else if (move->value == 5)
		rev_rotate(a);
	else if (move->value == 6)
		rev_rotate(b);
	else if (move->value == 7)
		rev_rrotate(a, b);
	else if (move->value == 8)
		rotate(a);
	else if (move->value == 9)
		rotate(b);
	else if (move->value == 10)
		rrotate(a, b);
}

static void	exec_move(t_stack *move, t_stack **a, t_stack **b)
{
	if ((move->value == 0 && *a && (*a)->next) || (move->value += 1) == -1)
		swap(*a);
	if ((move->value == 1 && *b && (*b)->next) || (move->value += 1) == -1)
		swap(*b);
	if ((move->value == 2 && *a && (*a)->next && (*b) && (*b)->next)
			|| (move->value += 1) == -1)
		sswap(*a, *b);
	if ((move->value == 3 && *a) || (move->value += 1) == -1)
		push(b, a);
	if ((move->value == 4 && *b) || (move->value += 1) == -1)
		push(a, b);
	if ((move->value == 5 && *a && (*a)->next) || (move->value += 1) == -1)
		rotate(a);
	if ((move->value == 6 && *b && (*b)->next) || (move->value += 1) == -1)
		rotate(b);
	if ((move->value == 7 && *a && (*a)->next && (*b) && (*b)->next)
			|| (move->value += 1) == -1)
		rrotate(a, b);
	if ((move->value == 8 && *a && (*a)->next) || (move->value += 1) == -1)
		rev_rotate(a);
	if ((move->value == 9 && *b && (*b)->next) || (move->value += 1) == -1)
		rev_rotate(b);
	if ((move->value == 10 && *a && (*a)->next && (*b) && (*b)->next)
			|| (move->value += 1) == -1)
		rev_rrotate(a, b);
}

static int	brute_loop(t_stack *move, t_stack **a, t_stack **b)
{
	if (is_sort(*a) && !(*b))
		return (1);
	if (!move)
		return (0);
	while (move->value < 11)
	{
		exec_move(move, a, b);
		if (brute_loop(move->next, a, b))
			return (1);
		undo_move(move, a, b);
		move->value += 1;
	}
	move->value = -1;
	return (0);
}

void		force(t_stack *move, t_stack **a, t_stack **b)
{
	while (!brute_loop(move, a, b))
		add_stack(&move, -1);
}
