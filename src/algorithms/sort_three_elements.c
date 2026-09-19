/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:43:25 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/19 20:43:25 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static  void    sort_two_elements(t_stack *stack_a, t_stats *stats)
{
    if (!stack_a || stack_a->size != 2)
        return ;
    if (compute_disorder(stack_a) == 0)
        return ;
    op_sa(stack_a, stats);
}

void    sort_three_elements(t_stack *stack_a, t_stats *stats)
{
    if (!stack_a || stack_a->size <  2 || stack_a->size > 3)
        return ;
    if (compute_disorder(stack_a) == 0)
        return ;
    if (stack_a->size == 2)
        return (sort_two_elements(stack_a, stats));
    index_stack(stack_a);
    if (stack_a->top->index == 0 && stack_a->top->next->index == 2)
        {
            op_sa(stack_a, stats);
            op_ra(stack_a, stats);
        }
    else if (stack_a->top->index == 1 && stack_a->top->next->index == 0)
        op_sa(stack_a, stats);
    else if (stack_a->top->index == 1 && stack_a->top->next->index == 2)
        op_rra(stack_a, stats);
    else if (stack_a->top->index == 2 && stack_a->top->next->index == 0)
        op_ra(stack_a, stats);
    else if (stack_a->top->index == 2 && stack_a->top->next->index == 1)
    {
        op_sa(stack_a, stats);
        op_rra(stack_a, stats);
    }
}
