/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:22:08 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/15 20:32:43 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	char	***results;
	t_stack *a;

	a = NULL;
	if (!(fill_stack(ac, av, &a)))
	{
		destroy_stack(&a);
		return (write(2, "Error\n", 6));
	}
	results = (char ***)malloc(sizeof(char **) * 6);
	if (!(result[0] = bubble_sort(a)))
		return (destroy_result(&a));
	if (!(result[1] = selection_sort(a)))
		return (destroy_result(&a));
	if (!(result[2] = insertion_sort(a)))
		return (destroy_result(&a));
	if (!(result[3] = quick_sort(a)))
		return (destroy_result(&a));
	if (!(result[4] = gnome_sort(a)))
		return (destroy_result(&a));
	if (!(result[5] = brute_sort(a)))
		return (destroy_result(&a));
	return (shortest_result(&results));
}