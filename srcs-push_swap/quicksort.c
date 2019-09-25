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

static t_part	**init_split(t_part *part, t_stack *a, t_stack *b)
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
	partitions[1]->op = stack_size(part->id == 'A' ? b : a);
	partitions[0]->ed = part->op + ((part->ed - part->op) / 2)
		+ (part->id == 'A' ? (part->ed - part->op) % 2 : 0);
	partitions[1]->ed = partitions[1]->op + ((part->ed - part->op) / 2)
		+ (part->id == 'B' ? (part->ed - part->op) % 2 : 0);
	return (partitions);
}

static void		sub_split(int *i, t_stack **a, t_stack **b, t_stack **mv)
{
	while (i[3] > 0)
	{
		add_to_stack(mv, i[0] ? 8 : 9, 1);
		rev_rotate(i[0] ? a : b);
		i[3]--;
	}
}

static t_part	**split_part(t_part *p, t_stack **mv, t_stack **a, t_stack **b)
{
	t_part	**partitions;
	int		i[4];
	int		med;

	i[0] = p->id == 'A' ? 1 : 0;
	med = part_median(p, i[0] ? *a : *b);
	if (!(partitions = init_split(p, *a, *b)))
		return (NULL);
	i[1] = 0;
	i[3] = 0;
	while (i[1] < partitions[1]->ed - partitions[1]->op)
	{
		i[2] = get_at(i[0] ? *a : *b, stack_size(i[0] ? *a : *b) - 1)->value;
		if (((i[2] >= med && !i[0]) || (i[2] < med && i[0])) && ++i[1])
		{
			add_to_stack(mv, i[0] ? 4 : 3, 1);
			push(i[0] ? a : b, i[0] ? b : a);
		}
		else if (++i[3] && rotate(i[0] ? a : b))
			add_to_stack(mv, i[0] ? 5 : 6, 1);
	}
	sub_split(i, a, b, mv);
	return (partitions);
}

static void		r_quicksort(t_part *p, t_stack **mv, t_stack **a, t_stack **b)
{
	t_part	**partitions;
	int		k;
	int		id;

	if (is_part_sort(p, *a, *b) || (is_sort(*a) && !(*b)))
		return ;
	if (!(partitions = split_part(p, mv, a, b)))
		return ;
	r_quicksort(partitions[0], mv, a, b);
	r_quicksort(partitions[1], mv, a, b);
	k = partitions[1]->op;
	id = p->id == 'A' ? 1 : 0;
	while (k < partitions[1]->ed)
	{
		push(id ? b : a, id ? a : b);
		add_to_stack(mv, id ? 3 : 4, 1);
		k++;
	}
	free(partitions[0]);
	free(partitions[1]);
	free(partitions);
}

t_stack			*quicksort(t_stack *orig)
{
	t_stack *moveset;
	t_stack	*a;
	t_stack *b;
	t_part	*part;

	moveset = NULL;
	a = NULL;
	b = NULL;
	if (!(dupe_stack(orig, &a, 0)) || !(init_part(&part, stack_size(a), 'A')))
	{
		if (!(add_to_stack(&moveset, -1, 0)))
			return (NULL);
		return (moveset);
	}
	r_quicksort(part, &moveset, &a, &b);
	destroy_stack(&a);
	destroy_stack(&b);
	free(part);
	return (moveset);
}
