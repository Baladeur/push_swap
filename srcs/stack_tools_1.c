/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:37:05 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 20:55:47 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			add_to_stack(t_stack **st, int nb, int boolean)
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
	while (pos->next && (boolean || pos->value != nb))
		pos = pos->next;
	if ((!boolean && pos->value == nb)
			|| !(pos = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	pos->next = *st;
	pos->value = nb;
	*st = pos;
	return (1);
}

void		dupe_stack(t_stack *src, t_stack **dest, int b)
{
	if (src)
	{
		if (src->next)
			dupe_stack(src->next, dest, b);
		add_to_stack(dest, src->value, b);
	}
}

static int	strnumcheck(char *av, int nb)
{
	int c1;
	int c2;

	c1 = av[0] == '-' || av[0] == '+' ? 1 : 0;
	c2 = 0;
	while (ft_isdigit(av[c1]))
		c1++;
	while (nb != 0 && ++c2)
		nb /= 10;
	if (av[0] == '-' || av[0] == '+')
		c1--;
	return (c1 != c2);
}

static int	skip_to_next_nb(char *av, int *k, int b)
{
	char c[2];

	while (av[*k])
	{
		c[0] = av[*k];
		c[1] = av[*k + 1];
		if (*k > 0 && av[*k - 1] >= '0' && av[*k - 1] <= '9'
			&& (c[0] == '-' || c[0] == '+'))
			return (0);
		if (b && (((c[0] == '-' || c[0] == '+') && c[1] >= '0' && c[1] <= '9')
			|| (c[0] >= '0' && c[0] <= '9')))
			return (1);
		else if (((c[0] == '-' || c[0] == '+') && c[1] >= '0' && c[1] <= '9')
			|| (c[0] >= '0' && c[0] <= '9'))
			*k += 1;
		else if (c[0] != ' ' && c[0] != 10 && c[0] != '	')
			return (0);
		else if ((*k += 1) >= 0)
			b = 1;
	}
	return (1);
}

int			fill_stack(int ac, char **av, t_stack **a)
{
	long int	nb;
	int			i;
	int			k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		if (!(skip_to_next_nb(av[i], &k, 1)))
			return (0);
		while (av[i][k])
		{
			nb = ft_atoi_l(av[i] + k);
			if (nb != (long int)((int)nb) || strnumcheck(av[i] + k, nb)
				|| !(add_to_stack(a, (int)nb, 0)))
				return (0);
			if (!(skip_to_next_nb(av[i], &k, 0)))
				return (0);
		}
		i++;
	}
	return (1);
}
