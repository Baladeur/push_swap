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

static t_stack	*revert_moveset(t_stack *moveset)
{
	t_stack *new;
	t_stack *pos;

	new = NULL;
	pos = moveset;
	while (pos)
	{
		add_to_stack(&new, pos->value, 1);
		pos = pos->next;
	}
	return (new);
}

static void		replace_n_free(t_stack **moveset, int id, int i, int k)
{
	t_stack	*pos;
	t_stack	*tmp;
	int		c;

	c = -1;
	pos = *moveset;
	while (++c < k)
	{
		pos->value = id;
		tmp = pos;
		pos = pos->next;
	}
	while (c < i)
	{
		tmp->next = pos->next;
		free(pos);
		pos = tmp->next;
		c++;
	}
}

static void		check_replace(t_stack **moveset, t_stack **st)
{
	t_stack	*pos;
	int		size;
	int		id;
	int		k;
	int		i;

	pos = *moveset;
	id = pos->value;
	i = 0;
	while (pos && pos->value == id)
	{
		pos = pos->next;
		i++;
	}
	size = stack_size(*st);
	if (i <= size / 2)
		return ;
	k = i % size;
	if (k > size / 2)
	{
		id += (id == 5 || id == 6) ? 3 : -3;
		k = size - k;
	}
	replace_n_free(moveset, id, i, k);
}

static void		clean_sort(t_stack **moveset, t_stack **a, t_stack **b)
{
	t_stack	*pos;
	int		move;

	pos = *moveset;
	while (pos)
	{
		move = pos->value;
		if (move == 5 || move == 8)
			check_replace(&pos, a);
		if (move == 6 || move == 9)
			check_replace(&pos, b);
		pos = pos->next;
	}
}

void			moveset_cleaner(t_stack **results, t_stack *orig)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*moveset;
	int		i;

	b = NULL;
	i = 0;
	while (i < 4)
	{
		a = NULL;
		b = NULL;
		moveset = NULL;
		dupe_stack(orig, &a);
		moveset = revert_moveset(results[i]);
		clean_sort(&moveset, &a, &b);
		destroy_stack(&b);
		destroy_stack(&a);
		destroy_stack(results + i);
		results[i] = revert_moveset(moveset);
		i++;
	}
}
