/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 10:22:30 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/25 10:22:32 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	can_exec(t_stack **a, t_stack **b, int mv)
{
	if (mv == 0 && stack_size(*a) >= 2)
		return (swap(*a));
	if (mv == 1 && stack_size(*b) >= 2)
		return (swap(*b));
	if (mv == 2 && stack_size(*a) >= 2 && stack_size(*b) >= 2)
		return (swap(*a) && swap(*b));
	if (mv == 3 && stack_size(*b) > 0)
		return (push(b, a));
	if (mv == 4 && stack_size(*a) > 0)
		return (push(a, b));
	if (mv == 5 && stack_size(*a) > 2)
		return (rotate(a));
	if (mv == 6 && stack_size(*b) > 2)
		return (rotate(b));
	if (mv == 7 && stack_size(*a) > 2 && stack_size(*b) > 2)
		return (rotate(a) && rotate(b));
	if (mv == 8 && stack_size(*a) > 2)
		return (rev_rotate(a));
	if (mv == 9 && stack_size(*b) > 2)
		return (rev_rotate(b));
	if (mv == 10 && stack_size(*a) > 2 && stack_size(*b) > 2)
		return (rev_rotate(a) && rev_rotate(b));
	return (0);
}

static void	undo_last(t_stack **a, t_stack **b, int mv)
{
	if (mv == 0 || mv == 2)
		swap(*a);
	if (mv == 1 || mv == 2)
		swap(*b);
	if (mv == 3)
		push(a, b);
	if (mv == 4)
		push(b, a);
	if (mv == 5 || mv == 7)
		rev_rotate(a);
	if (mv == 6 || mv == 7)
		rev_rotate(b);
	if (mv == 8 || mv == 10)
		rotate(a);
	if (mv == 9 || mv == 10)
		rotate(b);
}

static int	solver_backtrack(t_stack **moveset, t_stack **a, t_stack **b, int i)
{
	int k;

	k = 0;
	if (is_sort(*a) && !(*b))
		return (1);
	if (i == stack_size(*moveset))
		return (0);
	while (k < 11)
	{
		if (can_exec(a, b, k))
		{
			set_at(*moveset, i, k);
			if (solver_backtrack(moveset, a, b, i + 1))
				return (1);
			undo_last(a, b, get_at(*moveset, i)->value);
		}
		k++;
	}
	set_at(*moveset, i, -1);
	return (0);
}

t_stack		*brute_sort(t_stack *orig, int instructions_max)
{
	t_stack	*moveset;
	t_stack	*a;
	t_stack	*b;
	int		i;

	moveset = NULL;
	a = NULL;
	b = NULL;
	dupe_stack(orig, &a);
	add_to_stack(&moveset, -1, 1);
	i = 0;
	while (i < instructions_max)
	{
		if (solver_backtrack(&moveset, &a, &b, 0))
		{
			destroy_stack(&a);
			return (moveset);
		}
		add_to_stack(&moveset, -1, 1);
		i++;
	}
	destroy_stack(&a);
	return (moveset);
}
