/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   results_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 14:58:09 by tferrieu          #+#    #+#             */
/*   Updated: 2019/06/16 14:58:14 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	pattern_pxpy(t_stack **results, int i)
{
	t_stack	tmp1;
	t_stack	tmp2;
	int		id;
	int		size;

	size = stack_size(*results);
	if (i == size)
		return (0);
	id = get_at(*results, i)->value == 3 ? 0 : 1;
	if (get_at(*results, size - i - 1)->value != 4 - id)
		return (0);
	stack_destroy_one(*results, size - i);
	stack_destroy_one(*results, size - i - 1);
	return (1);
}

static int	pattern_sxsx(t_stack **results, int i)
{
	t_stack	*tmp;
	int		size;
	int		mv1;
	int		mv2;
	int		k;

	k = 1;
	size = stack_size(*results);
	mv1 = get_at(*results, size - i)->value;
	mv2 = -1;
	while (k + i <= size && (mv2 = get_at(*results, size - i - k)->value) != mv1
			&& mv1 != 2 && (mv2 == 1 - mv1 || mv2 == 6 - mv1 || mv2 == 9 - mv1))
		k++;
	if (mv2 != mv1)
		return (0);
	tmp = get_at(*results, size - i - 1);
	tmp->next = get_at(*results, size - i)->next;
	free(get_at(*results, size - i));
	if (k + i == size && tmp = get_at(*results, 0))
		*results = tmp->next;
	else if (tmp = get_at(*results, size - i - k))
		get_at(*results, size - i - k - 1)->next = tmp ->next;
	free(tmp);
	return (1);
}

static int	search_pattern(t_stack **results, t_stack **a, t_stack **b, int i)
{
	int size;
	int mv;
	int id;

	size = stack_size(*results);
	mv = get_at(*results, size - i);
	id = mv == 1 || mv == 4 || mv == 6 || mv == 9 ? 1 : 0;
	if (mv >= 0 && mv < 3 && pattern_sxsx(results, i))
		return (0);
	if (mv == mv > 4 && mv < 11 && patterm_rot(results, a, b, i))
		return (0);
	if (mv == 3 + id && pattern_pxpy(results, i))
		return (0);
	if (mv >= 0 && mv < 3 && pattern_sxrx(results, i, mv))
		return (0);
	if (mv > 7 && mv < 11 && pattern_rrxsx(results, i, mv))
		return (0);
	if (mv == 4 - id && pattern_pyrxpxrrx(results, a, b, i))
		return (0);
	return (1);
}
static int	moveset_cleaner(t_stack **results, t_stack **a, t_stack **b)
{
	int size;
	int i;
	
	size = stack_size(*results);
	i = 0;
	while (++i <= size)
	{
		if (search_pattern(results, a, b, i))
			return (0);
		exec_mv(a, b, get_at(a, b, *results, size - i)->value);
	}
	return (1);
}

void		results_cleaner(t_stack **results, t_stack *orig)
{
	t_stack *a;
	t_stack *b;
	int		i;

	i = 0;
	a = NULL;
	while (i < 5)
	{
		b = NULL;
		dupe_stack(orig, &a);
		while (!(moveset_cleaner(results + i, &a, &b)))
		{
			destroy_stack(&a);
			destroy_stack(&b);
			dupe_stack(orig, &a);
			b = NULL;
		}
		destroy_stack(&a);
		destroy_stack(&b);
		i++;
	}
}
