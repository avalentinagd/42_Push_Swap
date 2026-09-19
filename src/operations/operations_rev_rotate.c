/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 06:05:14 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/18 06:05:14 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static  void    op_reverse_aux(t_stack *stack)
{
    t_node  *bottom_node;

    bottom_node = pop_bottom(stack);
    stack_add_top(stack, bottom_node);
}

void    op_rra(t_stack *stack_a, t_stats *stats)
{
    if (!stack_a || stack_a->size < 2)
        return ;
    op_reverse_aux(stack_a);
    if (stats)
    {
        stats->rra++;
        stats->total_ops++;
    }
    write(1, "rra\n", 4);
}

void    op_rrb(t_stack *stack_b, t_stats *stats)
{
    if (!stack_b || stack_b->size < 2)
        return ;
    op_reverse_aux(stack_b);
    if (stats)
    {
        stats->rrb++;
        stats->total_ops++;
    }
    write(1, "rrb\n", 4);
}

void    op_rrr(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
    if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
        return ;
    op_reverse_aux(stack_a);
    op_reverse_aux(stack_b);
    if (stats)
    {
        stats->rrr++;
        stats->total_ops++;
    }
    write(1, "rrr\n", 4);
}