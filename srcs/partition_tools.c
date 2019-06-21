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
	while (i < part->ed)
	{
		if (id == 'A' && get_at(a, i + 1)->value > get_at(a, i)->value)
			return (0);
		if (id == 'B' && get_at(b, i + 1)->value > get_at(b, i)->value)
			return (0);
		i++;
	}
	return (1);
}