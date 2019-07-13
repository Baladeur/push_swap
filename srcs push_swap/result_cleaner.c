/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 15:17:26 by tferrieu          #+#    #+#             */
/*   Updated: 2019/07/06 15:17:28 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			secure_empty(t_stack **res, t_stack **a, t_stack **b, int i)
{
	int id;
	int mv;

	if (*a && *b)
		return (0);
	mv = get_at(*res, stack_size(*res) - i)->value;
	id = !(*a) ? 0 : 1;
	if (mv == 0 + id || mv == 4 - id || mv == 5 + id || mv == 8 + id)
		return (1);
	return (0);
}

static int	rotation_replace(t_stack **res, t_stack *st, int *c, int i)
{
	t_stack	*mv;
	int		sz[2];
	int		id;

	sz[0] = stack_size(*res);
	sz[1] = stack_size(st);
	id = (get_at(*res, sz[0] - i)->value - 5) % 3;
	while (c[0] % sz[1] && i <= sz[0])
	{
		mv = get_at(*res, sz[0] - i);
		if (mv->value == 5 + id || mv->value == 8 + id)
		{
			mv->value = c[0] % sz[1] > sz[1] / 2 ? 8 + id : 5 + id;
			c[0] += c[0] % sz[1] > sz[1] / 2 ? 1 : -1;
			c[1]--;
		}
		i++;
	}
	while (c[1] && i <= sz[0])
	{
		mv = get_at(*res, sz[0] - i);
		if ((mv->value == 5 + id || mv->value == 8 + id) && --c[1] > -1)
			destroy_at(res, sz[0] - i);
		i++;
	}
	return (1);
}

int			rota_cleaner(t_stack **res, t_stack **a, t_stack **b, int i)
{
	int c[3];
	int sz;
	int mv;
	int d;

	sz = stack_size(*res);
	d = (get_at(*res, sz - i)->value - 5) % 3;
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	if (d == 2 && stack_size(*a) != stack_size(*b))
		return (0);
	while (i + c[2] <= sz)
	{
		mv = get_at(*res, sz - i - c[2])->value;
		c[0] += mv == 5 + d ? 1 : 0;
		c[0] -= mv == 8 + d ? 1 : 0;
		c[1] += mv > 4 ? 1 : 0;
		if ((d == 2 && mv < 5) || mv == 3 || mv == 4 || mv == 2 || mv == 0 + d)
			break ;
		c[2]++;
	}
	if (c[0] > stack_size(d % 2 ? *b : *a) / 2)
		return (rotation_replace(res, d % 2 ? *b : *a, c, i));
	return (0);
}

static void	moveset_cleaner(t_stack **res, t_stack **a, int sz, int i)
{
	t_stack *b;
	int		mv;
	int		mv2;

	b = NULL;
	while (i <= sz)
	{
		mv = get_at(*res, sz - i)->value;
		mv2 = i < sz ? get_at(*res, sz - i - 1)->value : -1;
		if ((mv == 3 && mv2 == 4) || (mv == 4 && mv2 == 3))
		{
			destroy_at(res, sz - i - 1);
			destroy_at(res, sz - i - 1);
			i -= i > 1 ? 1 : 0;
		}
		else if (secure_empty(res, a, &b, i))
			destroy_at(res, sz - i);
		else if (mv > 4)
			i += 1 - rota_cleaner(res, a, &b, i);
		else if (++i)
			exec_mv(a, &b, mv);
		sz = stack_size(*res);
	}
	destroy_stack(&b);
}

void		results_cleaner(t_stack **res, t_stack *orig)
{
	t_stack	*a;
	t_stack *res_back;
	int		i;

	i = -1;
	while (++i < 5)
	{
		a = NULL;
		res_back = NULL;
		while (stack_size(orig) > 30 && i < 4)
			i++;
		dupe_stack(orig, &a, 0);
		dupe_stack(res[i], &res_back, 1);
		moveset_cleaner(res + i, &a, stack_size(res[i]), 1);
		destroy_stack(&a);
		if (!(moveset_checker(res[i], orig)))
		{
			a = NULL;
			dupe_stack(orig, &a, 0);
			destroy_stack(res + i);
			res[i] = res_back;
			safer_cleaner(res + i, &a, stack_size(res[i]), orig);
			destroy_stack(&a);
		}
		else
			destroy_stack(&res_back);
	}
}
