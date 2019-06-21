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

static void	go_to(t_stack **moveset, t_stack **a, int val)
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
		add_to_stack(moveset, k > size / 2 ? 8 : 5, 1);
		k += k > size / 2 ? 1 : -1;
	}
}

static void	move_at(t_stack **moveset, t_stack **a, int i, int d)
{
	t_stack	*b;
	int		size;
	int		top;

	b = NULL;
	size = stack_size(*a);
	top = get_at(*a, size - 1)->value;
	go_to(moveset, a, i);
	push(a, &b);
	add_to_stack(moveset, 4, 1);
	go_to(moveset, a, d);
	push(&b, a);
	add_to_stack(moveset, 3, 1);
	if (d != top)
		go_to(moveset, a, top);
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
	move_at(moveset, a, get_at(*a, size - i)->value,
			get_at(*a, size - i + pos)->value);
}

t_stack		*insertion_sort(t_stack *orig)
{
	t_stack	*a;
	t_stack	*moveset;
	int		i;

	a = NULL;
	moveset = NULL;
	dupe_stack(orig, &a);
	i = 1;
	while (!(is_sort(a)) && i <= stack_size(a))
	{
		insertion_loop(&moveset, &a, i);
		i++;
	}
	destroy_stack(&a);
	return (moveset);
}
