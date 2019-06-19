/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 14:58:09 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/16 14:58:14 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	fill_replace(t_stack **moveset, int *co, int mv)
{
	t_stack *pos;
	t_stack	*tmp;
	int		size;
	int		i;

	size = stack_size(*moveset);
	new = NULL;
	i = -1;
	while (++i < co[2])
		set_at(*moveset, size - co[0] - i - 1, mv);
	pos = get_at(*moveset, size - co[0] - co[2] - 1);
	tmp = get_at(*moveset, size - co[0] - co[2] - 1)->next;
	pos->next = get_at(*moveset, size - co[0] - co[1]);
	while (i < co[1])
	{
		pos = tmp->next;
		free(tmp);
		tmp = pos;
		i++;
	}
}

static void	clean_one(t_stack **moveset, t_stack **a, t_stack **b)
{
	int size;
	int i;

	size = stack_size(*moveset);
	i = 0;
	while (i < size)
	{

		size = stack_size(*moveset);
		if (/*CO[2] != 0*/)
			i++;
	}
}

void		moveset_cleaner(t_stack **results, t_stack *orig)
{
	t_stack *a;
	t_stack *b;
	int		i;

	i = 0;
	while (i < 4)
	{
		dupe_stack(orig, &a);
		b = NULL;
		clean_one(results[i], &a, &b);
		destroy_stack(&a);
		destroy_stack(&b);
		i++;
	}
}
