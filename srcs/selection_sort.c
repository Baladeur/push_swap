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
	add_to_stack(&mv, -1, 1);
	return (mv);
}

static void		biggest_to_b(t_stack **mv, t_stack **a, t_stack **b, int size)
{
	int max;
	int id;
	int i;

	id = 1;
	max = get_at(*a, size - 1)->value;
	i = 2;
	while (i <= size)
	{
		if (get_at(*a, size - i)->value < max && (id = i))
			max = get_at(*a, size - i)->value;
		i++;
	}
	while (id > 1 && id <= size)
	{
		add_to_stack(mv, id > size / 2 ? 8 : 5, 1);
		if (id > size / 2)
			rev_rotate(a);
		else
			rotate(a);
		id += id > size / 2 ? 1 : -1;
	}
	add_to_stack(mv, 4, 1);
	push(a, b);
}

t_stack			*selection_sort(t_stack *orig)
{
	t_stack *moveset;
	t_stack *a;
	t_stack *b;
	int		i;
	int		size;

	a = NULL;
	b = NULL;
	moveset = NULL;
	if (stack_size(orig) > 250)
		return (size_limit());
	dupe_stack(orig, &a);
	i = -1;
	size = stack_size(a);
	while (a)
	{
		biggest_to_b(&moveset, &a, &b, size);
		size--;
	}
	size = stack_size(orig);
	while (++i < size)
		add_to_stack(&moveset, 3, 1);
	destroy_stack(&b);
	return (moveset);
}
