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

static int	bubble_lloop(int *k, int size, t_stack **a, t_stack **moveset)
{
	while (*k < size && *k > 0 && !(is_sort(*a)))
	{
		if (*k > (size / 2))
			rotate(a);
		else
			rev_rotate(a);
		if (!(add_to_stack(moveset, *k > (size / 2) ? 5 : 8, 1)))
			return (0);
		*k += *k > (size / 2) ? 1 : -1;
	}
	return (1);
}

static int	bubble_loop(t_stack **a, int size, int i, t_stack **moveset)
{
	int k;

	k = -1;
	while (++k < size - i - 1 && !(is_sort(*a)))
	{
		if ((get_at(*a, size - 2))->value < (get_at(*a, size - 1))->value)
		{
			if (!(add_to_stack(moveset, 0, 1)))
				return (0);
			swap(*a);
		}
		if (!(is_sort(*a)))
		{
			if (!(add_to_stack(moveset, 5, 1)))
				return (0);
			rotate(a);
		}
	}
	return (bubble_lloop(&k, size, a, moveset));
}

t_stack		*bubble_sort(t_stack *orig)
{
	t_stack	*a;
	t_stack *moveset;
	int		size;
	int		i;

	a = NULL;
	moveset = NULL;
	if ((size = stack_size(orig)) > 100 || !(dupe_stack(orig, &a, 0)))
	{
		if (!(add_to_stack(&moveset, -1, 1)))
			return (NULL);
		return (moveset);
	}
	i = -1;
	while ((i++) >= -1 && i < size - 1 && !(is_sort(a)))
	{
		if (!(bubble_loop(&a, size, i, &moveset)))
		{
			destroy_stack(&a);
			destroy_stack(&moveset);
			return (NULL);
		}
	}
	destroy_stack(&a);
	return (moveset);
}
