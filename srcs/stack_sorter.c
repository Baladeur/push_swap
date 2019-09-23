/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:37:02 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 20:56:55 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	sort_loop(t_stack **a, t_stack **b, char *str, int len)
{
	if (len == 2 && str[0] == 's' && str[1] == 'a')
		return (swap(*a));
	else if (len == 2 && str[0] == 's' && str[1] == 'b')
		return (swap(*b));
	else if (len == 2 && str[0] == 's' && str[1] == 's')
		return (swap(*a) && swap(*b));
	else if (len == 2 && str[0] == 'p' && str[1] == 'a')
		return (push(b, a));
	else if (len == 2 && str[0] == 'p' && str[1] == 'b')
		return (push(a, b));
	else if (len == 2 && str[0] == 'r' && str[1] == 'a')
		return (rotate(a));
	else if (len == 2 && str[0] == 'r' && str[1] == 'b')
		return (rotate(b));
	else if (len == 2 && str[0] == 'r' && str[1] == 'r')
		return (rotate(a) && rotate(b));
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		return (rev_rotate(a));
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		return (rev_rotate(b));
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		return (rev_rotate(a) && rev_rotate(b));
	else
		return (0);
}

int			sort_stack(t_stack **a, t_stack **b)
{
	char	*str;
	int		bol;

	while ((bol = get_next_move(0, &str)) && ft_strlen(str))
	{
		if (!(sort_loop(a, b, str, ft_strlen(str))) || bol < 0)
		{
			free(str);
			return (0);
		}
		free(str);
	}
	free(str);
	return (1);
}

int			is_sort(t_stack *st)
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

int			is_rev_sort(t_stack *st)
{
	t_stack *pos;

	pos = st;
	while (pos && pos->next)
	{
		if (pos->value > pos->next->value)
			return (0);
		pos = pos->next;
	}
	return (1);
}
