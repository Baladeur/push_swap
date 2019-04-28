/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 16:51:21 by tferrieu          #+#    #+#             */
/*   Updated: 2019/04/28 16:51:22 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int  brute_loop(t_stack *moveset, t_stack *a, t_stack *b)
{
    if (!moveset)
        return (0);
    if (is_sort(a) && !b)
        return (1)
    while (moveset->value < 11)
    {
        exec_move(moveset, a, b);
        if (brute_loop(moveset->next, a, b))
            return (1);
        moveset->value += 1;
    }
}

void brute(t_stack *moveset, t_stack *a, t_stack *b)
{
    while (!brute_loop(moveset, a, b))
        add_stack(&moveset, 0);
}