/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:36:56 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 20:56:42 by tferrieu         ###   ########.fr       */
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

static int	sort_stack(t_stack **a, t_stack **b)
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

int			main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!(fill_stack(ac, av, &a)))
	{
		destroy_stack(&a);
		return (write(2, "Error\n", 6));
	}
	if (!(sort_stack(&a, &b)))
	{
		destroy_stack(&a);
		destroy_stack(&b);
		return (write(2, "Error\n", 6));
	}
	if (is_sort(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
