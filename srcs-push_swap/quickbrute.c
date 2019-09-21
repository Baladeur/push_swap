/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickbrute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:54:25 by tferrieu          #+#    #+#             */
/*   Updated: 2019/09/18 12:54:27 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	undo_mv(t_stack **a, t_stack **b, int mv)
{
	if (mv >= 0 && mv <= 2)
		return (exec_mv(a, b, mv));
	if (mv == 3)
		return (exec_mv(a, b, 4));
	if (mv == 4)
		return (exec_mv(a, b, 3));
	if (mv >= 5 && mv <= 7)
		return (exec_mv(a, b, mv + 3));
	if (mv >= 8 && mv <= 10)
		return (exec_mv(a, b, mv - 3));
	return (0);
}

static int	is_part_valid(t_part *p, t_stack **brute, t_stack **a, t_stack **b)
{
	t_stack	*st;
	int		i;

	i = 0;
	st = p->id == 'A' ? *a : *b;
	while (p->op + i < p->ed)
	{
		if (!(find_nb(brute[1], get_at(st, p->op + i)->value)))
			return (0);
		i++;
	}
	return (is_part_sort(p, *a, *b));
}

static int	quicksolve(t_part *p, t_stack **brute, t_stack **a, t_stack **b)
{
	t_stack	*s;
	int		i;
	int		m;

	if (is_part_valid(p, brute, a, b))
		return (1);
	i = 0;
	s = brute[0];
	while (s && s->value < 0 && ++i)
		s = s->next;
	if (s == NULL)
		return (0);
	m = 0;
	while (m < 11)
	{
		set_at(brute[0], i, m);
		exec_mv(a, b, m);
		if (quicksolve(p, brute, a, b))
			return (1);
		undo_mv(a, b, m);
		m++;
	}
	set_at(brute[0], i, -1);
	return (0);
}

static void	create_back(t_stack **brute, t_part *p, t_stack **a, t_stack **b)
{
	t_stack	*st;
	int		i;

	i = 0;
	st = p->id == 'A' ? *a : *b;
	while (p->op + i < p->ed)
	{
		add_to_stack(&(brute[1]), get_at(st, p->op + i)->value, 1);
		i++;
	}
}

void		quickbrute(t_part *p, t_stack **mv, t_stack **a, t_stack **b)
{
	t_stack	**brute;
	int		i;

	if (!(brute = (t_stack **)malloc(sizeof(t_stack *) * 2)))
		return ;
	brute[0] = NULL;
	brute[1] = NULL;
	add_to_stack(brute, -1, 1);
	create_back(brute, p, a, b);
	i = 0;
	while (!(is_part_valid(p, brute, a, b)) && i < 9 && ++i)
	{
		if (quicksolve(p, brute, a, b))
		{
			get_at(*mv, stack_size(*mv))->next = brute[0];
			destroy_stack(&(brute[1]));
			free(brute);
			return ;
		}
		add_to_stack(brute, -1, 1);
	}
	destroy_stack(&(brute[0]));
	destroy_stack(&(brute[1]));
	free(brute);
}
