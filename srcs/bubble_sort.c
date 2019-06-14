/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:39:31 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/14 12:39:34 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**bubble_sort(t_stack *orig)
{
	t_stack	*a;
	t_stack	*pos;
	int		size;

	size = 0;
	if (!(orig) || !(*orig))
		return (NULL);
	pos = orig;
	a = dupe_stack(orig);
	while (pos && size++)
		pos = pos->next;
	
}