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

static void	destroy_moveset(t_stack **moveset)
{
	int i;

	i = 0;
	while (i < 5)
	{
		destroy_stack(moveset + i);
		i++;
	}
	free(moveset);
}

static void	print_moveset(t_stack *moveset)
{
	int		t;

	if (moveset->next)
		print_moveset(moveset->next);
	t = moveset->value;
	if (t >= 0 && t <= 2)
		ft_printf("s");
	if (t == 3 || t == 4)
		ft_printf("p");
	if (t >= 5 && t <= 7)
		ft_printf("r");
	if (t >= 8 && t <= 10)
		ft_printf("rr");
	if (t == 0 || t == 3 || t == 5 || t == 8)
		ft_printf("a\n");
	if (t == 1 || t == 4 || t == 6 || t == 9)
		ft_printf("b\n");
	if (t == 2)
		ft_printf("s\n");
	if (t == 7 || t == 10)
		ft_printf("r\n");
}

static int	shortest_result(t_stack ***results)
{
	int	i;
	int	id;
	int	shortest;
	int tmp;

	shortest = 2147483647;
	id = 0;
	i = 0;
	while (i < 5)
	{
		if ((tmp = stack_size((*results)[i])) < shortest
				&& (!(*results)[i] || (*results)[i]->value >= 0))
		{
			shortest = tmp;
			id = i;
		}
		i++;
	}
	if (shortest)
		print_moveset((*results)[id]);
	destroy_moveset(*results);
	return (1);
}

int			main(int ac, char **av)
{
	t_stack	**results;
	t_stack *a;

	a = NULL;
	if (ac == 1 || ac == 2)
		return (0);
	if (!(fill_stack(ac, av, &a))
		|| !(results = (t_stack **)malloc(sizeof(t_stack *) * 5)))
	{
		destroy_stack(&a);
		return (write(2, "Error\n", 6));
	}
	results[0] = bubble_sort(a);
	results[1] = gnome_sort(a);
	results[2] = selection_sort(a);
	results[3] = insertion_sort(a);
	results[4] = quicksort(a);
	ft_printf("[0] : %d | [1] : %d | [2] : %d | [3] : %d | [4] : %d\n",
	stack_size(results[0]), stack_size(results[1]), stack_size(results[2]), stack_size(results[3]), stack_size(results[4]));
	//results_cleaner(results, a);
	destroy_stack(&a);
	return (shortest_result(&results));
}
