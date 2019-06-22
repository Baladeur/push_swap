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
	int i;
	int c;
	int u;
	int m;

	m = -1;
	i = part->op;
	while (i < part->ed)
	{
		u = part->op;
		c = 0;
		while (u < part->ed)
		{
			c += get_at(st, part->op + u)->value > get_at(st, part->op + i)->value ? 1 : 0;
			c += get_at(st, part->op + u)->value < get_at(st, part->op + i)->value ? -1 : 0;
			u++;
		}
		if (!c && i > m)
			m = i;
		i++;
	}
	return (get_at(st, part->op + m)->value);
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

	ft_printf("i\n");
	id = part->id;
	curr = id == 'A' ? a : b;
	i = part->op;
	ft_printf("%d | %d\n", i, part->ed);
	while (i + 1 < part->ed)
	{
		if (id == 'A' && get_at(a, i + 1)->value > get_at(a, i)->value)
		{
			ft_printf("o\n");
			return (0);
		}
		if (id == 'B' && get_at(b, i + 1)->value > get_at(b, i)->value)
		{
			ft_printf("o\n");
			return (0);
		}
		i++;
	}
	ft_printf("o\n");
	return (1);
}
