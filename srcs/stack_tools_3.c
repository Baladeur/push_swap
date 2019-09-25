/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:53:48 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/30 15:53:51 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	destroy_at(t_stack **st, int i)
{
	t_stack	*tmp;
	int		size;

	size = stack_size(*st);
	if (i >= size)
		return ;
	tmp = get_at(*st, i);
	if (i > 0)
		get_at(*st, i - 1)->next = tmp->next;
	else
		*st = tmp->next;
	free(tmp);
}

void	destroy_stack(t_stack **st)
{
	t_stack	*tmp;
	t_stack	*pos;

	pos = *st;
	while (pos)
	{
		tmp = pos->next;
		free(pos);
		pos = tmp;
	}
	*st = NULL;
}

int		moveset_checker(t_stack *moveset, t_stack *orig)
{
	t_stack	*a;
	t_stack	*b;
	int		size;
	int		i;
	int		boolean;

	i = 0;
	a = NULL;
	b = NULL;
	if (!(dupe_stack(orig, &a, 0)))
		return (0);
	size = stack_size(moveset);
	while (++i <= size)
		exec_mv(&a, &b, get_at(moveset, size - i)->value);
	boolean = is_sort(a) && !b ? 1 : 0;
	destroy_stack(&a);
	destroy_stack(&b);
	return (boolean);
}
