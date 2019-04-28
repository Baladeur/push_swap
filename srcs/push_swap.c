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

static void	print_id(int nb)
{
	if (nb == 0)
		ft_printf("sa\n");
	else if (nb == 1)
		ft_printf("sb\n");
	else if (nb == 2)
		ft_printf("ss\n");
	else if (nb == 3)
		ft_printf("pa\n");
	else if (nb == 4)
		ft_printf("pb\n");
	else if (nb == 5)
		ft_printf("ra\n");
	else if (nb == 6)
		ft_printf("rb\n");
	else if (nb == 7)
		ft_printf("rr\n");
	else if (nb == 8)
		ft_printf("rra\n");
	else if (nb == 9)
		ft_printf("rrb\n");
	else if (nb == 10)
		ft_printf("rrr\n");
}

static void	print_moveset(t_stack **moveset)
{
	t_stack *tmp;
	t_stack *pos;

	pos = *moveset;
	*moveset = NULL;
	while (pos)
	{
		tmp = pos->next;
		print_id(pos->value);
		free(pos);
		pos = tmp;
	}
}

int			main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	t_stack	*moveset;

	a = NULL;
	b = NULL;
	if (!(fill_stack(ac, av, &a)))
	{
		destroy_stack(&a);
		return (write(2, "Error\n", 6));
	}
	moveset = NULL;
	if (!(add_stack(&moveset, -1)))
		return (write(2, "Error\n", 6));
	force(moveset, &a, &b);
	print_moveset(&moveset);
	return (0);
}
