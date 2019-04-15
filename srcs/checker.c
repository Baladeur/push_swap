/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:36:56 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 19:21:39 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (!(fill_stack(ac, av, &a)))
	{
		destroy_stack(&a);
		return (write(2, "Error\n", 6));
	}
	print_stack(a);
	if (!(sort_stack(&a, &b)))
	{
		destroy_stack(&a);
		destroy_stack(&b);
		return (write(2, "Error\n", 6));
	}
	print_stack(a);
	if (is_sort(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	destroy_stack(&a);
	destroy_stack(&b);
	return (0);
}
