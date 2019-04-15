/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moveset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:37:00 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 19:09:41 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *st)
{
	t_stack	*pos;
	int		tmp;

	if (!st || !(st->next))
		return ;
	pos = st;
	while (pos->next->next)
		pos = pos->next;
	tmp = pos->next->value;
	pos->next->value = pos->value;
	pos->value = tmp;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*pos1;
	t_stack	*pos2;

	if (!(*src))
		return ;
	pos1 = *src;
	while (pos1->next && pos1->next->next)
		pos1 = pos1->next;
	if (!(*dst))
		*dst = pos1->next ? pos1->next : pos1;
	else
	{
		pos2 = *dst;
		while (pos2->next)
			pos2 = pos2->next;
		pos2->next = pos1->next ? pos1->next : pos1;
	}
	if (!((*src)->next))
		*src = NULL;
	else
		pos1->next = NULL;
}

void	rotate(t_stack **st)
{
	t_stack *pos;

	if (!(*st) || !((*st)->next))
		return ;
	pos = (*st);
	while (pos->next->next)
		pos = pos->next;
	pos->next->next = *st;
	*st = pos->next;
	pos->next = NULL;
}

void	rev_rotate(t_stack **st)
{
	t_stack *pos;

	if (!(*st) || !((*st)->next))
		return ;
	pos = *st;
	while (pos->next)
		pos = pos->next;
	pos->next = *st;
	*st = (*st)->next;
	pos->next->next = NULL;
}
