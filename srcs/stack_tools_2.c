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

void	print_stacks(t_stack *a, t_stack *b)
{
	int k_a;
	int k_b;
	int size_a;
	int size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	k_a = size_a;
	k_b = size_b;
	while (k_a > k_b)
	{
		ft_printf("%d\t|\t\n", get_at(a, k_a - 1)->value);
		k_a--;
	}
	while (k_b > k_a)
	{
		ft_printf("\t|\t%d\n", get_at(b, k_b - 1)->value);
		k_b--;
	}
	k_a++;
	while (--k_a > 0)
		ft_printf("%d\t|\t%d\n", get_at(a, k_a - 1)->value,
					get_at(b, k_a - 1)->value);
	ft_printf("-\t|\t-\nA\t|\tB\n");
}
