/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:37:02 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 19:20:40 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sswap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void		rrotate(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

void		rev_rrotate(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}

static int	sort_loop(t_stack **a, t_stack **b, char *str, int len)
{
	if (len == 2 && str[0] == 's' && str[1] == 'a')
		swap(*a);
	else if (len == 2 && str[0] == 's' && str[1] == 'b')
		swap(*b);
	else if (len == 2 && str[0] == 's' && str[1] == 's')
		sswap(*a, *b);
	else if (len == 2 && str[0] == 'p' && str[1] == 'a')
		push(b, a);
	else if (len == 2 && str[0] == 'p' && str[1] == 'b')
		push(a, b);
	else if (len == 2 && str[0] == 'r' && str[1] == 'a')
		rotate(a);
	else if (len == 2 && str[0] == 'r' && str[1] == 'b')
		rotate(b);
	else if (len == 2 && str[0] == 'r' && str[1] == 'r')
		rrotate(a, b);
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
		rev_rotate(a);
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
		rev_rotate(b);
	else if (len == 3 && str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
		rev_rrotate(a, b);
	else
		return (0);
	return (1);
}

int			sort_stack(t_stack **a, t_stack **b)
{
	char	*str;

	while (get_next_line(0, &str) && ft_strlen(str))
	{
		if (!(sort_loop(a, b, str, (int)ft_strlen(str))))
		{
			free(str);
			return (0);
		}
		free(str);
		ft_printf("stack a status\t: ");
		print_stack(*a);
		ft_printf("stack b status\t: ");
		print_stack(*b);

	}
	free(str);
	return (1);
}
