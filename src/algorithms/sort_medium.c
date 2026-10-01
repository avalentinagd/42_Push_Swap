/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 02:45:48 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/30 02:45:48 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static  int ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}


	//chunk_size = ft_sqrt(stack_a->size);
	// if (stack_a->size > 100) // Si tenemos más de 100 args, amplíamos el tamaño del bloque un 50% (1.5 x sqrt{N}) para reducir las rotaciones innecesarias en A
	// 	chunk_size = chunk_size * 3 / 2;
static  void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	int	chunk_size;
	int	low;
	int	high;

    chunk_size = ft_sqrt(stack_a->size);
    if (stack_a->size <= 100)
        chunk_size = chunk_size * (13 / 10);
    else
        chunk_size = chunk_size * (15 / 10);
    low = 0; // Inicializamos el rango de la ventana. Al principio, el rango aceptado de índices va desde 0 hasta chunk_size.
	high = chunk_size;
	while (stack_a->size > 0) // El bucle se detiene cuando la pila quede vacía
	{
		if (stack_a->top->index <= high) // Comprueba si top entra en el rango. Cualquien arg con index <= high se puede envíar a B
		{
			op_pb(stack_a, stack_b, stats); // el nodo pasa al top de B
            if (stack_b->top->index < (low + chunk_size) / 2) // preordenamos B, si el nodo pertenece a la mitad inferior del rango [low. high] actual, ejecuta rb
                op_rb(stack_b, stats);                        // punto medio del bloque: (low + chunk_size) / 2
			low++;
			high++;
		}
		else // si top->index > high, ejecuta ra para elviarlo al fondo y evaluar el siguiente nodo.
			op_ra(stack_a, stats);
	}
}

void	sort_medium(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	/* Aseguramos que los elementos tengan su índice asignado de 0 a N-1 */
	index_stack(stack_a);

	/* 1. Vaciamos A por chunks enviando elementos preordenados a B */
	push_chunks_to_b(stack_a, stack_b, stats);

	/* 2. Reconstruimos A extrayendo el máximo de B en cada paso */
	while (stack_b->size > 0)
	{
		push_max_to_a(stack_a, stack_b, stats);
	}
}