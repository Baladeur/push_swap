/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_swap_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 11:04:09 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/30 11:04:11 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	replace_sxrx(t_stack **results, int i, int *x, int k)
{
	int size;

	size - stack_size(*results);
	if (i + x[0] + k < x[1] / 2 + 2)
		return (0);
	
}

int			pattern_sxrx(t_stack **results, int i, int id)
{
	int x[2];
	int size;
	int mv;
	int k;

	size = stack_size(*results);
	if (id == 2)
		return (pattern_sxrx(results, i, 0) || pattern_sxrx(results, i, 1));
	x[0] = 1;
	x[1] = 0;
	k = 0;
	while (i + x[0] <= size && (mv = get_at(results, size - i - x[0])->value)
		&& mv != 3 && mv != 4 && mv != 8 && mv != 10)
	{
		if (mv == 0 + id && (x[1] % 2) || (mv == 2 && (x[1] % 2) && ++k))
			x++;
		else if (mv == 5 + id && !(x[1] % 2) || (mv == 7 && !(x[1] % 2) && ++k))
			x++;
		else if (mv == 0 + id || mv == 5 + id || mv == 7 || mv == 2)
			break;
		x[0]++;
	}
	return (replace_sxrx(results, i, x, k));
}
