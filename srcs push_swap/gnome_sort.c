/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnome_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 20:12:52 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/16 20:12:54 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	exception_ra(t_stack *orig)
{
	t_stack *a;
	int		i;
	int		m;
	int		sz;

	a = NULL;
	sz = stack_size(orig);
	i = get_at(orig, sz - 1)->value;
	m = i;
	dupe_stack(orig, &a, 0);
	destroy_at(&a, sz - 1);
	while (--sz)
	{
		if (get_at(orig, sz - 1)->value >= m)
			m = get_at(orig, sz - 1)->value;
	}
	if (is_sort(a) && i == m)
	{
		destroy_stack(&a);
		return (1);
	}
	destroy_stack(&a);
	return (0);
}

static void	gnome_loop(t_stack **a, t_stack **moveset, int size)
{
	int b_ascend;
	int k;

	k = 1;
	b_ascend = 0;
	while (k < size && !(is_sort(*a)))
	{
		if ((get_at(*a, size - 2))->value < (get_at(*a, size - 1))->value)
		{
			add_to_stack(moveset, 0, 1);
			swap(*a);
			b_ascend = 0;
		}
		if (!b_ascend && k == 0)
			b_ascend = 1;
		if (!(is_sort(*a)))
		{
			add_to_stack(moveset, b_ascend ? 5 : 8, 1);
			if ((b_ascend))
				rotate(a);
			else
				rev_rotate(a);
		}
		k += b_ascend ? 1 : -1;
	}
}

t_stack		*gnome_sort(t_stack *orig)
{
	t_stack	*a;
	t_stack *moveset;
	int		size;

	a = NULL;
	moveset = NULL;
	if (stack_size(orig) > 100)
	{
		add_to_stack(&moveset, -1, 1);
		return (moveset);
	}
	if (exception_ra(orig))
	{
		add_to_stack(&moveset, 5, 1);
		return (moveset);
	}
	size = 0;
	dupe_stack(orig, &a, 0);
	size = stack_size(orig);
	gnome_loop(&a, &moveset, size);
	destroy_stack(&a);
	return (moveset);
}
