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
		return (NULL);
	k = 0;
	pos = src;
	while (pos && k < i)
	{
		pos = pos->next;
		k++;
	}
	if (pos)
		pos->value = v;

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
