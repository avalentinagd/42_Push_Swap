/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 07:37:38 by angalleg          #+#    #+#             */
/*   Updated: 2026/10/01 07:37:38 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int	max_num;
	int	max_bits;

	max_num = stack->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) > 0)
		max_bits++;
	return (max_bits); // EJ: (max_bits = 7) nos dice que se debe repetir el bucle del Radix Sort exactamente 7 veces.
}

void	sort_complex(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		size = stack_a->size;
		j = 0;
		while (j < size)
		{ // (index >> bit) mueve el bit que nos interesa a la primera posición a la derecha
			if (((stack_a->top->index >> i) & 1) == 0) // & 1 solo mira el último bit de la derecha, devuelve 1(si es impar, termina en 1) o 0(si es par, termina en 0).
				op_pb(stack_a, stack_b, stats);// Si el bit es 0, va a B
			else
				op_ra(stack_a, stats);// Si el bit es 1, se queda en A (rota hacia arriba)
			j++;
		}
		while (stack_b->size > 0)
			op_pa(stack_a, stack_b, stats);
		i++;
	}
}
