/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:23:58 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/21 14:23:59 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		part_median(t_part *part, t_stack *st)
{
	int g[2];
	int i[3];

	i[0] = part->op;
	i[1] = part->op;
	g[0] = (part->ed - part->op + 1) % 2;
	while (i[0] < part->ed)
	{
		i[2] = part->op;
		g[1] = 0;
		while (i[2] < part->ed)
		{
			g[1] += get_at(st, i[0])->value > get_at(st, i[2])->value ? 1 : 0;
			g[1] -= get_at(st, i[0])->value < get_at(st, i[2])->value ? 1 : 0;
			i[2]++;
		}
		if (g[1] == g[0])
			i[1] = i[0];
		i[0]++;
	}
	return (get_at(st, i[1])->value);
}

int		init_part(t_part **part, int size, int id)
{
	if (!(*part = (t_part *)malloc(sizeof(t_part))))
		return (0);
	(*part)->ed = size;
	(*part)->op = 0;
	(*part)->id = id;
	return (1);
}

int		is_part_sort(t_part *part, t_stack *a, t_stack *b)
{
	t_stack	*curr;
	int		id;
	int		i;

	id = part->id;
	curr = id == 'A' ? a : b;
	i = part->op;
	while (i + 1 < part->ed)
	{
		if (id == 'A' && get_at(a, i + 1)->value > get_at(a, i)->value)
			return (0);
		if (id == 'B' && get_at(b, i + 1)->value < get_at(b, i)->value)
			return (0);
		i++;
	}
	return (1);
}

void	print_part(t_part *p, t_stack *st)
{
	int k;

	k = p->op - 1;
	while (++k < p->ed)
		ft_printf("%d\t", get_at(st, k)->value);
	ft_printf("\n");
}
