/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:37:02 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 20:56:55 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			is_sort(t_stack *st)
{
	t_stack *pos;

	pos = st;
	while (pos && pos->next)
	{
		if (pos->value < pos->next->value)
			return (0);
		pos = pos->next;
	}
	return (1);
}

int			is_rev_sort(t_stack *st)
{
	t_stack *pos;

	pos = st;
	while (pos && pos->next)
	{
		if (pos->value > pos->next->value)
			return (0);
		pos = pos->next;
	}
	return (1);
}
