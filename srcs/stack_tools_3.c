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
		*st = tmp ->next;
	free(tmp);
}

void	move_at(t_stack **st, int orig, int dst)
{
	t_stack *tmp1;
	t_stack *tmp2;

	if (orig == dst)
		return ;
	tmp1 = get_at(*st, orig);
	if (orig == 0)
		*st = tmp1->next;
	tmp1->next = get_at(*st, dst - dst > orig ? 1 : 0);
	if (dst == 0)
		*st = tmp1;
	else 
}