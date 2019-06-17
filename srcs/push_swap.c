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

static void	destroy_moveset(t_stack ***moveset)
{
	int i;

	i = 0;
	while (i < 1)
	{
		destroy_stack(*(moveset + i));
		i++;
	}
	free(*moveset);
	*moveset = NULL;
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

	ft_printf("Dummy 1\n");
	shortest = stack_size((*results)[0]);
	id = 0;
	i = 1;
	ft_printf("Dummy 2\n");
	while (i < 3)
	{
		ft_printf("Dummy 2.1\n");
		if ((tmp = stack_size((*results)[i])) < shortest
				&& (!(*results[i]) || (*results[i])->value >= 0))
		{
			ft_printf("Dummy 2.2\n");
			shortest = tmp;
			id = i;
		}
		ft_printf("Dummy 2.3\n");
		i++;
	}
	ft_printf("Dummy 3\n");
	if (shortest)
		print_moveset((*results)[id]);
	ft_printf("Dummy 4\n");
	destroy_moveset(results);
	ft_printf("Dummy 5\n");
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
		|| !(results = (t_stack **)malloc(sizeof(t_stack *) * 3)))
	{
		destroy_stack(&a);
		return (write(2, "Error\n", 6));
	}
	results[0] = bubble_sort(a);
	results[1] = gnome_sort(a);
	results[2] = selection_sort(a);
	/*results[3] = insertion_sort(a);
	results[4] = quick_sort(a);
	results[5] = brute_sort(a);*/
	ft_printf("[0] : %d | [1] : %d | [2] : %d\n", stack_size(results[0]), stack_size(results[1]), stack_size(results[2]));
	moveset_cleaner(results, a);
	ft_printf("[0] : %d | [1] : %d | [2] : %d\n", stack_size(results[0]), stack_size(results[1]), stack_size(results[2]));
	destroy_stack(&a);
	return (shortest_result(&results));
}
