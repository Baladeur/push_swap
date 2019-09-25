/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safer_cleaner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 01:46:02 by tferrieu          #+#    #+#             */
/*   Updated: 2019/07/07 01:46:04 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	clean_loop(t_stack **res, t_stack **a, t_stack **b, int *mv)
{
	int sz;

	sz = stack_size(*res);
	mv[0] = get_at(*res, sz - mv[2])->value;
	mv[1] = mv[2] < sz ? get_at(*res, sz - mv[2] - 1)->value : -1;
	if ((mv[0] == 3 && mv[1] == 4) || (mv[0] == 4 && mv[1] == 3))
	{
		destroy_at(res, sz - mv[2] - 1);
		destroy_at(res, sz - mv[2] - 1);
		mv[2] -= mv[2] > 1 ? 1 : 0;
	}
	else if (secure_empty(res, a, b, mv[2]))
		destroy_at(res, sz - mv[2]);
	else if (mv[0] > 4)
		mv[2] += 1 - rota_cleaner(res, a, b, mv[2]);
	else if (++mv[2])
		exec_mv(a, b, mv[0]);
}

static void	init_cleaner(t_stack **a, t_stack **b, t_stack **c, t_stack **d)
{
	*a = NULL;
	*b = NULL;
	*c = NULL;
	*d = NULL;
}

static int	safe_dupe(t_stack **res, t_stack **a, t_stack **dum, t_stack **d_a)
{
	if (!(dupe_stack(*res, dum, 1)))
		return (0);
	if (!(dupe_stack(*a, d_a, 0)))
	{
		destroy_stack(dum);
		return (0);
	}
	return (1);
}

int			safer_cleaner(t_stack **res, t_stack **a, int sz, t_stack *o)
{
	t_stack *b;
	t_stack *dummy;
	t_stack *d_b;
	t_stack *d_a;
	int		mv[2][3];

	init_cleaner(&b, &dummy, &d_b, &d_a);
	if (!(safe_dupe(res, a, &dummy, &d_a)))
		return (0);
	mv[0][2] = 1;
	mv[1][2] = 1;
	while (mv[0][2] <= sz && (sz = stack_size(dummy)))
	{
		clean_loop(&dummy, &d_a, &d_b, mv[0]);
		if (moveset_checker(dummy, o))
			clean_loop(res, a, &b, mv[1]);
		else
			break ;
	}
	destroy_stack(&dummy);
	destroy_stack(&d_a);
	destroy_stack(&d_b);
	destroy_stack(&b);
	return (1);
}
