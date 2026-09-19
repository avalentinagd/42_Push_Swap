/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 06:05:07 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/18 06:05:07 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static  void    op_rotate_aux(t_stack *stack)
{
    t_node  *top_node;

    top_node = pop_top(stack);
    stack_add_bottom(stack, top_node);
}

void    op_ra(t_stack *stack_a, t_stats *stats)
{
    if (!stack_a || stack_a->size < 2)
        return ;
    op_rotate_aux(stack_a);
    if (stats)
    {
        stats->ra++;
        stats->total_ops++;
    }
    write(1, "ra\n", 3);
}

void    op_rb(t_stack *stack_b, t_stats *stats)
{
    if (!stack_b || stack_b->size < 2)
        return ;
    op_rotate_aux(stack_b);
    if (stats)
    {
        stats->rb++;
        stats->total_ops++;
    }
    write(1, "rb\n", 3);
}

void    op_rr(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
    if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
        return ;
    op_rotate_aux(stack_a);
    op_rotate_aux(stack_b);
    if (stats)
    {
        stats->rr++;
        stats->total_ops++;
    }
    write(1, "rr\n", 3);
}