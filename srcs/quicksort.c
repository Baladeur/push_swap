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

static t_part	init_split(t_part *part, t_stack *a, t_stack *b)
{
	t_part	**partitions;

	if (!(partitions = (t_part **)malloc(sizeof(t_part *) * 2)))
		return (NULL);
	if (!(partitions[0] = (t_part *)malloc(sizeof(t_part))))
	{
		free(partitions);
		return (NULL);
	}
	if (!(partitions[1] = (t_part *)malloc(sizeof(t_part))))
	{
		free(partitions[1]);
		free(partitions);
		return (NULL);
	}
	partitions[0]->id = part->id;
	partitions[1]->id = part->id == 'A' ? 'B' : 'A';
	partitions[0]->op = part->op;
	partitions[1]->op =	stack_size(id == 'A' ? b : a);
	partitions[0]->ed = part->op + (part->ed - part->op) / 2
		+ part->id == 'A' ? (part->ed - part->op) % 2 : 0;
	partitions[1]->ed =	partitions[1]->op + (part->ed - part-op) / 2
		+ part->id == 'B' ? (part->ed - part->op) % 2 : 0;
	return (partitions);
}

static t_part	**split_part(t_part *part, t_stack **mv, t_stack **a, t_stack **b)
{
	t_part	**partitions;
	int		id;
	int		k;
	int		i;
	int		med;

	
	k = 0;
	med = part_median(part, id ? a : b);
}

static void		rec_quicksort(t_part *part, t_stack **mv, t_stack **a, t_stack **b)
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