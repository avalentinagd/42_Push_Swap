/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:06:05 by marvin            #+#    #+#             */
/*   Updated: 2026/09/10 05:06:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

void	init_stats(t_stats *stats)
{
	stats->bench = 0;
	stats->strategy_name = "Adaptive";
	stats->total_ops = 0;
	stats->sa = 0;
	stats->sb = 0;
	stats->ss = 0;
	stats->pa = 0;
	stats->pb = 0;
	stats->ra = 0;
	stats->rb = 0;
	stats->rr = 0;
	stats->rra = 0;
	stats->rrb = 0;
	stats->rrr = 0;
}

void	print_parsed_stack(t_stack *a, t_stats *stats)
{
	t_node	*curr;
	int		i;

	printf("\n=== RESULTADO DEL PARSEO ===\n");
	printf("Estrategia activa: %s\n", stats->strategy_name);
	printf("Modo Bench: %s\n", stats->bench ? "ACTIVADO" : "DESACTIVADO");
	printf("Tamaño del Stack A: %d\n", a->size);
	printf("Contenido del Stack A (Top -> Bottom):\n");
	curr = a->top;
	i = 0;
	while (curr)
	{
		printf("  [%d] -> Valor: %d\n", i, curr->value);
		curr = curr->next;
		i++;
	}
	printf("===========================\n\n");
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stats	stats;

	if (argc < 2)
		return (0);

	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	init_stats(&stats);

	if (!parse_arguments(argc, argv, &a, &stats))
	{
		write(2, "Error\n", 6);
		free_stack(&a); // Liberar nodos en caso de error
		return (1);
	}

	print_parsed_stack(&a, &stats);
	
	// Limpieza de nodos
	t_node *curr = a.top;
	t_node *next;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	return (0);
}

// Compilación y Prueba:

// # Compilar el test
// cc -Wall -Wextra -Werror -I include -I libft test_parser.c src/parser.c src/parse_utils.c src/parse_flags.c src/stack_utils.c libft/libft.a -o test_parser

// # Prueba 1: Números sueltos
// ./test_parser 42 -10 0 100

// # Prueba 2: Entre comillas
// ./test_parser "42 -10 0 100"

// # Prueba 3: Con flags y mezcla de argumentos
// ./test_parser --bench --simple 2 "1 3" 6 "5"

// # Prueba 4: Error (Debe imprimir Error\n por stderr)
// ./test_parser 1 2 tres 4