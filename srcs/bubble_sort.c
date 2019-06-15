/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:39:31 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/14 12:39:34 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	bubble_loop(t_stack **a, int size, int i, t_stack **moveset)
{
	int k;

	k = 0;
	while (k < i)
	{
		add_to_stack(moveset, 8, 1);
		rev_rotate(a);
		k++;
	}
	while (k < size && !(is_sort(*a)))
	{
		if ((get_at(*a, size - 2))->value < (get_at(*a, size - 1))->value)
		{
			add_to_stack(moveset, 0, 1);
			swap(*a);
		}
		if (!(is_sort(*a)))
			add_to_stack(moveset, 8, 1);
		rev_rotate(a);
		k++;
	}
}

t_stack		*bubble_sort(t_stack *orig)
{
	t_stack	*a;
	t_stack *moveset;
	int		size;
	int		i;

	a = NULL;
	moveset = NULL;
	size = 0;
	if (!orig)
	{
		add_to_stack(&a, -1, 1);
		return (a);
	}
	dupe_stack(orig, &a);
	size = stack_size(orig);
	i = 0;
	while (i < size && !(is_sort(a)))
	{
		bubble_loop(&a, size, i, &moveset);
		i++;
	}
	destroy_stack(&a);
	print_stack(moveset);
	return (moveset);
}
