/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 03:28:58 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/29 03:28:58 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_simple(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	/* Si la pila tiene 5 o menos elementos desde el principio, 
	   llamamos directamente a la función de casos pequeños */
	if (stack_a->size <= 5)
	{
		sort_five(stack_a, stack_b, stats);
		return ;
	}

	/* Reducimos 'a' hasta que queden exactamente 5 elementos */
	while (stack_a->size > 5)
		push_min_to_b(stack_a, stack_b, stats);

	/* Ordenamos los 5 elementos restantes que quedan en 'a' */
	sort_five(stack_a, stack_b, stats);

	/* Devolvemos todos los elementos acumulados en 'b' de vuelta a 'a' */
	while (stack_b->size > 0)
		op_pa(stack_a, stack_b, stats);
}