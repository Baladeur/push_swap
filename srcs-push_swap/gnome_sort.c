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
	if (!(dupe_stack(orig, &a, 0)))
		return (-1);
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

static int	ascend_check(t_stack **a, t_stack **moveset, int b_ascend)
{
	if (!(is_sort(*a)))
	{
		if (!(add_to_stack(moveset, b_ascend ? 5 : 8, 1)))
			return (0);
		if ((b_ascend))
			rotate(a);
		else
			rev_rotate(a);
	}
	return (1);
}

static int	gnome_loop(t_stack **a, t_stack **moveset, int size)
{
	int b_ascend;
	int k;

	k = 1;
	b_ascend = 0;
	while (k < size && !(is_sort(*a)))
	{
		if ((get_at(*a, size - 2))->value < (get_at(*a, size - 1))->value)
		{
			if (!(add_to_stack(moveset, 0, 1)))
				return (0);
			swap(*a);
			b_ascend = 0;
		}
		if (!b_ascend && k == 0)
			b_ascend = 1;
		if (!(ascend_check(a, moveset, b_ascend)))
			return (0);
		k += b_ascend ? 1 : -1;
	}
	return (1);
}

t_stack		*gnome_sort(t_stack *orig)
{
	t_stack	*a;
	t_stack *moveset;
	int		size;
	int		err;

	a = NULL;
	moveset = NULL;
	if ((size = stack_size(orig)) > 100 || !(dupe_stack(orig, &a, 0))
		|| (err = exception_ra(orig)))
	{
		if (!(add_to_stack(&moveset, size < 100
			&& err == 1 ? 5 : -1, 1)))
			return (NULL);
		return (moveset);
	}
	if (!(gnome_loop(&a, &moveset, size)))
	{
		destroy_stack(&a);
		destroy_stack(&moveset);
		return (NULL);
	}
	destroy_stack(&a);
	return (moveset);
}
