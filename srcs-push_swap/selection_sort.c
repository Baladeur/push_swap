/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:16:16 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/17 19:16:17 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*size_limit(void)
{
	t_stack *mv;

	mv = NULL;
	if (!(add_to_stack(&mv, -1, 1)))
		return (NULL);
	return (mv);
}

static int		biggest_to_b(t_stack **mv, t_stack **a, t_stack **b, int size)
{
	int max;
	int id;
	int i;

	id = 1;
	max = get_at(*a, size - 1)->value;
	i = 1;
	while (i++ <= size)
	{
		if (get_at(*a, size - i)->value < max && (id = i))
			max = get_at(*a, size - i)->value;
	}
	while (id > 1 && id <= size && (id += id > size / 2 + 1 ? 1 : -1) >= 0)
	{
		if (!(add_to_stack(mv, id > size / 2 + 1 ? 8 : 5, 1)))
			return (0);
		if (id > size / 2 + 1)
			rev_rotate(a);
		else
			rotate(a);
	}
	if (!(add_to_stack(mv, 4, 1)))
		return (0);
	push(a, b);
	return (1);
}

static int		selection_loop(t_stack **a, t_stack **b, t_stack **mv, int *sz)
{
	while (*a)
	{
		if (!(biggest_to_b(mv, a, b, *sz)))
		{
			destroy_stack(a);
			destroy_stack(b);
			destroy_stack(mv);
			return (0);
		}
		(*sz)--;
	}
	return (1);
}

static int		selection_lloop(t_stack **b, t_stack **moveset, int size)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (!(add_to_stack(moveset, 3, 1)))
		{
			destroy_stack(b);
			destroy_stack(moveset);
			return (0);
		}
	}
	return (1);
}

t_stack			*selection_sort(t_stack *orig)
{
	t_stack *moveset;
	t_stack *a;
	t_stack *b;
	int		size;

	a = NULL;
	b = NULL;
	moveset = NULL;
	if ((size = stack_size(orig)) > 250 || !(dupe_stack(orig, &a, 0)))
		return (size_limit());
	if (!(selection_loop(&a, &b, &moveset, &size)))
		return (NULL);
	if (!(selection_lloop(&b, &moveset, stack_size(orig))))
		return (NULL);
	destroy_stack(&b);
	return (moveset);
}
