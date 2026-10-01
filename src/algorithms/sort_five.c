/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 01:30:39 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/26 01:30:39 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_five(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	if (!stack_a || stack_a->size < 2 || stack_a->size > 5)
		return ;
	if (compute_disorder(stack_a) == 0)
		return ;
	index_stack(stack_a);
	if (stack_a->size == 5)
		push_min_to_b(stack_a, stack_b, stats);
	index_stack(stack_a);
	if (stack_a->size == 4)
		push_min_to_b(stack_a, stack_b, stats);
	index_stack(stack_a);
	sort_three(stack_a, stats);
	while (stack_b->size > 0)
		op_pa(stack_a, stack_b, stats);
    index_stack(stack_a); // tal vez no es necesaria esta linea, solo si necesitara indexar el stack A
}
