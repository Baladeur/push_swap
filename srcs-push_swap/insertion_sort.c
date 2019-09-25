/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 09:52:00 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/18 09:52:03 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	go_to(t_stack **moveset, t_stack **a, int val)
{
	int	size;
	int k;

	k = 0;
	size = stack_size(*a);
	while (get_at(*a, size - k - 1)->value != val)
		k++;
	while (k > 0 && k < size)
	{
		if (k > size / 2)
			rev_rotate(a);
		else
			rotate(a);
		if (!(add_to_stack(moveset, k > size / 2 ? 8 : 5, 1)))
			return (0);
		k += k > size / 2 ? 1 : -1;
	}
	return (1);
}

static int	move_to(t_stack **moveset, t_stack **a, int i, int d)
{
	t_stack	*b;
	int		size;
	int		top;

	b = NULL;
	size = stack_size(*a);
	top = get_at(*a, size - 1)->value;
	if (!(go_to(moveset, a, i)))
		return (0);
	push(a, &b);
	if (!(add_to_stack(moveset, 4, 1)) || !(go_to(moveset, a, d)))
	{
		destroy_stack(&b);
		return (0);
	}
	push(&b, a);
	if (!(add_to_stack(moveset, 3, 1)))
		return (0);
	if (d != top && !go_to(moveset, a, top))
		return (0);
	return (1);
}

static int	insertion_loop(t_stack **moveset, t_stack **a, int i)
{
	int	smallest;
	int size;
	int curr;
	int pos;
	int c;

	smallest = 2147483647;
	size = stack_size(*a);
	pos = -1;
	c = 0;
	while (c++ >= 0 && c < i)
	{
		curr = get_at(*a, size - i + c)->value;
		if (curr > get_at(*a, size - i)->value && curr < smallest)
		{
			pos = c;
			smallest = curr;
		}
	}
	if (pos < 0)
		return (1);
	if (!(move_to(moveset, a, get_at(*a, size - i)->value,
			get_at(*a, size - i + pos)->value)))
		return (0);
	return (1);
}

t_stack		*insertion_sort(t_stack *orig)
{
	t_stack	*a;
	t_stack	*moveset;
	int		i;

	a = NULL;
	moveset = NULL;
	if (stack_size(orig) > 100 || !(dupe_stack(orig, &a, 0)))
	{
		if (!(add_to_stack(&moveset, -1, 1)))
			return (NULL);
		return (moveset);
	}
	i = 1;
	while (!(is_sort(a)) && i <= stack_size(a))
	{
		if (!(insertion_loop(&moveset, &a, i)))
		{
			destroy_stack(&a);
			destroy_stack(&moveset);
			return (NULL);
		}
		i++;
	}
	destroy_stack(&a);
	return (moveset);
}
