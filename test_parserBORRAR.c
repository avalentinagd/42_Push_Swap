/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 05:06:05 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/10 05:06:05 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

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
	t_stack	*a;
	t_stats	stats;

	if (argc < 2)
		return (0);

	init_stats(&stats); // Inicializamos las estadísticas a cero
	stats.bench = 1; // Para probar la función, activamos el modo bench a mano temporalmente
	a = init_stack(); // Creamos la estructura del stack en memoria con init_stack que hace malloc
	if (!a)
		return (1);
	// Lee los argumentos y llena el stack 'a'
	if (!parse_arguments(argc, argv, a, &stats)) 
	{
		free_stack(a); // Es seguro y limpia los nodos en caso de error
		return (1); // Ya se imprimió "Error\n" por dentro desde parse_arguments()
	}
	stats.disorder = compute_disorder(a); // CALCULAR E IMPRIMIR EL ÍNDICE
	//printf("Índice de desorden inicial: %f\n", disorder);

	print_parsed_stack(a, &stats); // Resultado visual del parseo (mi función de prueba)
	print_bench_results(&stats); // MOSTRAR LAS ESTADÍSTICAS POR LA TERMINAL (STDOUT/STDERR)
	
	free_stack(a); // Limpiamos toda la memoria antes de salir
	return (0);
}


// Compilación y Prueba:

// # Compilar el test
// cc -g -Wall -Wextra -Werror -I include -I libft test_parserBORRAR.c src/stats.c src/parser.c src/parse_utils.c src/parse_flags.c src/stack_utils.c libft/libft.a -o test_parser

// # Prueba 1: Números sueltos
// ./test_parser 42 -10 0 100

// # Prueba 2: Entre comillas
// ./test_parser "42 -10 0 100"

// # Prueba 3: Con flags y mezcla de argumentos
// ./test_parser --bench --simple 2 "1 3" 6 "5"

// # Prueba 4: Error (Debe imprimir Error\n por stderr)
// ./test_parser 1 2 tres 4

// Prueba 5 duplicados: 
// valgrind ./test_parser 2 3 2

// Prueba 6 caracteres inválidos: 
// valgrind ./test_parser 2 "3 a" 5

// Prueba 7 desbordamiento (Overflow): (un número mayor al INT_MAX).
// valgrind ./test_parser 2147483648 