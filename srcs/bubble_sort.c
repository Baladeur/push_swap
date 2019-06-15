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
	while (k < size - i && !(is_sort(*a)))
	{
		if ((get_at(*a, size - 2))->value < (get_at(*a, size - 1))->value)
		{
			add_to_stack(moveset, 0, 1);
			swap(*a);
		}
		if (!(is_sort(*a)))
		{
			add_to_stack(moveset, 5, 1);
			rotate(a);
		}
		k++;
	}
	while (k < size && k > 0 && !(is_sort(*a)))
	{
		if (k > (size / 2))
			rotate(a);
		else
			rev_rotate(a);
		add_to_stack(moveset, k > (size / 2) ? 5 : 8, 1);
		k += k > (size / 2) ? 1 : -1;
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
	return (moveset);
}
