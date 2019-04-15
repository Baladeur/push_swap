/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:37:05 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 20:55:47 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		add_stack(t_stack **st, int nb)
{
	t_stack	*pos;

	if (!*st)
	{
		if (!(*st = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		(*st)->value = nb;
		(*st)->next = NULL;
		return (1);
	}
	pos = *st;
	while (pos->next && pos->value != nb)
		pos = pos->next;
	if (pos->value == nb || !(pos = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	pos->next = *st;
	pos->value = nb;
	*st = pos;
	return (1);
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

int		is_sort(t_stack *st)
{
	t_stack *pos;

	pos = st;
	while (pos && pos->next)
	{
		if (pos->value < pos->next->value)
			return (0);
		pos = pos->next;
	}
	return (1);
}

int		fill_stack(int ac, char **av, t_stack **a)
{
	long int	nb;
	int			i;
	int			k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		while (av[i][k] && !(k && (av[i][k] == '-' || av[i][k] == '+'))
				&& ((av[i][k] >= '0' && av[i][k] <= '9') || (av[i][k] == '-')
					|| (av[i][k] == '+')))
			k++;
		if (av[i][k])
			return (0);
		nb = ft_atoi_l(av[i]);
		if (nb != (long int)((int)nb) || !add_stack(a, (int)nb))
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(t_stack *st)
{
	t_stack *pos;

	pos = st;
	while (pos)
	{
		ft_printf("%d", pos->value);
		if (pos->next)
			ft_printf("\t");
		pos = pos->next;
	}
	ft_printf("\n");
}
