/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:17:00 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/20 13:17:01 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	split_part(t_part *part, t_stack **mv, t_stack **a, t_stack **b)
{
	

}

static void	rec_quicksort(t_part *part, t_stack **mv, t_stack **a, t_stack **b)
{
	t_part	**partitions;
	int		k;
	int		id;

	if (is_part_sort(part, *a, *b) || (is_sort(*a) && !(*b))
		|| !(partitions = split_part(part, moveset, a, b)))
		return ;
	rec_quicksort(partitions[0], mv, a, b);
	rec_quicksort(partitions[1], mv, a, b);
	k = 0;
	id = part->id == 'A' ? 1 : 0;
	while (k < part->ed)
	{
		push(id ? a : b, id ? b : a);
		add_to_stack(mv, id ? 4 : 3);
		k++;
	}
	free(partitions[0]);
	free(partitions[1]);
	free(partitions);
}

t_stack		*quicksort(t_stack *orig)
{
	t_stack *moveset;
	t_stack	*a;
	t_stack *b;
	t_part	*part;

	moveset = NULL;
	a = NULL;
	b = NULL;
	dupe_stack(orig, &a);
	if (!(init_part(&part, stack_size(a), 'A')))
	{
		add_to_stack(&moveset, -1, 0);
		return (moveset);
	}
	rec_quicksort(part, &moveset, &a, &b);
	destroy_stack(&a);
	destroy_stack(&b);
	return (moveset);
}