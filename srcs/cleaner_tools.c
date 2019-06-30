/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:17:24 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/28 10:17:27 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		pattern_pyrxpxrrx(t_stack **results, t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;
	int		size;
	int		id;

	size = stack_size(*results);
	id = get_at(*results, i) == 4 ? 1 : 0;
	if (i + 3 > size || get_at(size - i - 1)->value != 6 - id
		|| get_at(size - i - 2)->value != 4 - id
		|| get_at(size - i - 3)->value != 9 - id)
		return (0);
	tmp = get_at(size - i - 2);
	get_at(*results, i - 3)->value = 1 - id;
	get_at(*results, i - 3)->next = get_at(*results, i)->next;
	free(tmp->next->next);
	free(tmp->next);
	free(tmp);
	return (1);
}