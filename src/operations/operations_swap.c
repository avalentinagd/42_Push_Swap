/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 06:04:01 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/18 06:04:01 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static	void	op_swap_aux(t_stack *stack)
{
    int temp_value;
    int temp_index;

	// Guardamos los datos del primer nodo
    temp_value = stack->top->value;
    temp_index = stack->top->index;
	// Copiamos los datos del segundo nodo en el primero
    stack->top->value = stack->top->next->value;
    stack->top->index = stack->top->next->index;
	// Asignamos los datos guardados al segundo nodo
    stack->top->next->value = temp_value;
    stack->top->next->index = temp_index;
}

void	op_sa(t_stack *stack_a, t_stats *stats)
{
	if (!stack_a || stack_a->size < 2)
	return ;
    op_swap_aux(stack_a);
    // Actualizamos métricas si stats existe
    if (stats)
    {
        stats->sa++;
        stats->total_ops++;
    }
    // Imprimimos el movimiento
    write(1, "sa\n", 3);
}

void	op_sb(t_stack *stack_b, t_stats *stats)
{
	if (!stack_b || stack_b->size < 2)
	return ;
    op_swap_aux(stack_b);
    if (stats)
    {
        stats->sb++;
        stats->total_ops++;
    }
    write(1, "sb\n", 3);
}

void	op_ss(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	if (!stack_a || !stack_b || stack_a->size < 2 || stack_b->size < 2)
		return ;
    op_swap_aux(stack_a);
	op_swap_aux(stack_b);
    if (stats)
    {
        stats->ss++;
        stats->total_ops++;
    }
    write(1, "ss\n", 3);
}
