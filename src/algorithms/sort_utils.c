/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 03:20:33 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/29 03:20:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Buscamos la distancia del mínimo a la cima
int	get_min_distance(t_stack *stack, int min_index)
{
	t_node	*curr;
	int		dist;

	curr = stack->top;
	dist = 0;
	while (curr)
	{
		if (curr->index == min_index)
			return (dist);
		dist++;
		curr = curr->next;
	}
	return (dist);
}

void	push_min_to_b(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	dist;

	index_stack(stack_a); // Nos aseguramos de que el menor de 'a' siempre tenga index == 0
	dist = get_min_distance(stack_a, 0);
	if (dist <= stack_a->size / 2)
	{
		while (stack_a->top->index != 0)
			op_ra(stack_a, stats);
	}
	else
	{
		while (stack_a->top->index != 0)
			op_rra(stack_a, stats);
	}
	op_pb(stack_a, stack_b, stats);
}
// Buscamos la distancia desde el máximo(max_index) a la cima
int	get_max_distance(t_stack *stack, int max_index)
{
	t_node	*curr;
	int		dist;

	curr = stack->top;
	dist = 0;
	while (curr)
	{
		if (curr->index == max_index)
			return (dist);
		dist++;
		curr = curr->next;
	}
	return (dist);
}

void	push_max_to_a(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	max_index;
	int	dist;

	max_index = stack_b->size - 1;
	dist = get_max_distance(stack_b, max_index);
	if (dist <= stack_b->size / 2)
	{
		while (stack_b->top->index != max_index) //rotamos hasta que el nodo con index == max_index quede situado en la cima de B (stack_b->top).
			op_rb(stack_b, stats);
	}
	else
	{
		while (stack_b->top->index != max_index) //rotamos hasta que el nodo con index == max_index quede situado en la cima de B (stack_b->top).
			op_rrb(stack_b, stats);
	}
	op_pa(stack_a, stack_b, stats);
}
