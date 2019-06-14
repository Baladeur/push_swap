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
	while (k < size)
	{
		if (get_at(*a, size - 1)->value > get_at(*a, size)->value)
		{
			add_to_stack(moveset, 0, 1);
			swap(*a);
		}
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

	size = 0;
	if (!orig || !*orig)
		return (NULL);
	a = dupe_stack(orig);
	size = stack_size(orig);
	i = 0;
	while (i < size)
		bubble_loop(&a, size, i, &moveset);
	if (!(is_sort(a)))
	{
		destroy_stack(&a);
		return (NULL);
	}
	destroy_stack(&a);
	return (moveset);
}
