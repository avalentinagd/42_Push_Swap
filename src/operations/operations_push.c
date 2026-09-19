/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 20:05:43 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/17 20:05:43 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    op_pa(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
    t_node *node;

    if (!stack_a || !stack_b || stack_b->size == 0)
        return ;
    node = pop_top(stack_b);
    stack_add_top(stack_a, node);
    if (stats)
    {
        stats->pa++;
        stats->total_ops++;
    }
    write(1, "pa\n", 3);
}

void    op_pb(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
    t_node *node;

    if (!stack_a || !stack_b || stack_a->size == 0)
        return ;
    node = pop_top(stack_a);
    stack_add_top(stack_b, node);
    if (stats)
    {
        stats->pb++;
        stats->total_ops++;
    }
    write(1, "pb\n", 3);
}
