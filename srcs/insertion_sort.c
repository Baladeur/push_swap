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

static void	move_at(t_stack **moveset, t_stack **a, int i, int d)
{
	t_stack	*b;
	int		size;
	int		n;

	b = NULL;
	size = stack_size(*a);
	n = 1;
	while ((i - n > 0 && i - n < size) && !(is_sort(*a)))
	{
		if (i - n > size / 2)
			rev_rotate(a);
		else
			rotate(a);
		add_to_stack(moveset, i - n > size / 2 ? 8 : 5, 1);
		n += i - n > size / 2 ? -1 : 1;
	}
	push(a, &b);
	add_to_stack(moveset, 4, 1);
	while (d > 0 && d < size - 1)
	{
		if (d > (size - 1) / 2)
			rotate(a);
		else
			rev_rotate(a);
		add_to_stack(moveset, d > (size - 1) / 2 ? 5 : 8, 1);
		n += d > (size - 1) / 2 ? 1 : -1;
		d += d > (size - 1) / 2 ? 1 : -1;
	}
	push(&b, a);
	add_to_stack(moveset, 3, 1);
	while (n > 1 && n < size + 1);
	{
	}
}

static void	insertion_loop(t_stack **moveset, t_stack **a, int i)
{
	int	smallest;
	int size;
	int curr;
	int pos;
	int c;

	smallest = 2147483647;
	size = stack_size(*a);
	pos = -1;
	c = 1;
	while (c < i)
	{
		curr = get_at(*a, size - i + c)->value;
		if (curr > get_at(*a, size - i)->value && curr < smallest)
		{
			pos = c;
			smallest = curr;
		}
		c++;
	}
	if (pos < 0)
		return ;
	move_at(moveset, a, i, pos);
}

t_stack		*insertion_sort(t_stack *orig)
{
	t_stack	*a;
	t_stack	*moveset;
	int		i;

	a = NULL;
	moveset = NULL;
	dupe_stack(orig, &a);
	i = 2;
	while (!(is_sort(a)) && i < stack_size(a))
	{
		print_stack(a);
		print_stack(moveset);
		insertion_loop(&moveset, &a, i);
		i++;
	}
	destroy_stack(&a);
	return (moveset);
}
