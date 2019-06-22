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
	partitions[1]->op =	stack_size(part->id == 'A' ? b : a);
	partitions[0]->ed = part->op + (part->ed - part->op) / 2
		+ part->id == 'A' ? (part->ed - part->op) % 2 : 0;
	partitions[1]->ed =	partitions[1]->op + (part->ed - part->op) / 2
		+ part->id == 'B' ? (part->ed - part->op) % 2 : 0;
	return (partitions);
}

static t_part	**split_part(t_part *part, t_stack **mv, t_stack **a, t_stack **b)
{
	t_part	**partitions;
	int		i[4];
	int		med;

	i[0] = part->id == 'A' ? 1 : 0;
	med = part_median(part, i[0] ? *a : *b);
	if (!(partitions = init_split(part, *a, *b)))
		return (NULL);
	i[1] = 0;
	i[3] = 0;
	while (i[1] < partitions[1]->ed - partitions[1]->op)
	{
		i[2] = get_at(i[0] ? *a : *b, stack_size(i[0] ? *a : *b) - 1)->value;
		if ((i[2] >= med && !i[0]) || (i[2] < med && i[0]))
		{
			add_to_stack(mv, i[0] ? 4 : 3, 1);
			push(i[0] ? a : b, i[0] ? b : a);
			i[1]++;
		}
		else
		{
			add_to_stack(mv, i[0] ? 5 : 6, 1);
			rotate(i[0] ? a : b);
			i[3]++;
		}
	}
	while (i[3] > 0)
	{
		add_to_stack(mv, i[0] ? 8 : 9, 1);
		rev_rotate(i[0] ? a : b);
		i[3]--;
	}
	return (partitions);
}

static void		rec_quicksort(t_part *part, t_stack **mv, t_stack **a, t_stack **b)
{
	t_part	**partitions;
	int		k;
	int		id;

	print_stacks(*a, *b);
	ft_printf("\t1\n");
	if (is_part_sort(part, *a, *b) || (is_sort(*a) && !(*b))
		|| !(partitions = split_part(part, mv, a, b)))
	{

		ft_printf("\t->\n");
		return ;
	}
	ft_printf("\t2\n");
	rec_quicksort(partitions[0], mv, a, b);
	ft_printf("\t3\n");
	rec_quicksort(partitions[1], mv, a, b);
	ft_printf("\t4\n");
	k = 0;
	id = part->id == 'A' ? 1 : 0;
	while (k < part->ed)
	{
		push(id ? a : b, id ? b : a);
		add_to_stack(mv, id ? 4 : 3, 1);
		k++;
	}
	ft_printf("\t5\n");
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
