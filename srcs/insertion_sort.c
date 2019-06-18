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

static void move_at(t_stack **moveset, t_stack **a, int i, int d)
{
	t_stack	*b;
	int		size;
	int		pos;
	int		n;

	b = NULL;
	size = stack_size(*a);
	n = 0;
	while (n + i > 0 && n + i <= size && !(is_sort(a)))
	{
		//ra ou rra pour aller jusqu'à i;
	}
	push(a, &b);
	add_to_stack(moveset, 4, 1);
	while (n + d > 0 && n + d <= size)
	{
		//ra ou rra pour aller jusqu'à d;
	}
	push(&b, a);
	add_to_stack(moveset, 3, 1);
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
		curr = get_at(a, size - c)->value;
		if (curr > get_at(a, size - i) && curr < smallest)
		{
			pos = c;
			smallest = curr;
		}
		i++;
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
	b = NULL;
	moveset = NULL;
	dupe_stack(orig, &a);
	i = 1;
	while (!(is_sort(a)) || b)
	{
		insertion_loop(&moveset, &a, i);
		i++;
	}
	destroy_stack(&a);
	destroy_stack(&b);
	return (moveset);
}