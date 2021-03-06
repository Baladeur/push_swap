/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:37:05 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 20:55:47 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		exec_mv(t_stack **a, t_stack **b, int mv)
{
	if (mv == 0)
		return (swap(*a));
	if (mv == 1)
		return (swap(*b));
	if (mv == 2)
		return (swap(*a) && swap(*b));
	if (mv == 3)
		return (push(b, a));
	if (mv == 4)
		return (push(a, b));
	if (mv == 5)
		return (rotate(a));
	if (mv == 6)
		return (rotate(b));
	if (mv == 7)
		return (rotate(a) && rotate(b));
	if (mv == 8)
		return (rev_rotate(a));
	if (mv == 9)
		return (rev_rotate(b));
	if (mv == 10)
		return (rev_rotate(a) && rev_rotate(b));
	return (0);
}

t_stack	*get_at(t_stack *src, int i)
{
	t_stack	*pos;
	int		k;

	if (!src)
		return (NULL);
	k = 0;
	pos = src;
	while (pos && k < i)
	{
		pos = pos->next;
		k++;
	}
	if (k < i)
		return (NULL);
	else
		return (pos);
}

void	set_at(t_stack *src, int i, int v)
{
	t_stack	*pos;
	int		k;

	if (!src)
		return ;
	k = 0;
	pos = src;
	while (pos && k < i)
	{
		pos = pos->next;
		k++;
	}
	if (pos)
		pos->value = v;
}

int		stack_size(t_stack *st)
{
	int i;

	if (!st)
		return (0);
	i = 0;
	while (st && ++i)
		st = st->next;
	return (i);
}
