/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 23:04:05 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/08 23:04:05 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Verifica si el número ya existe en el stack
static int	is_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	if (!stack)
		return (0);
	current = stack->top;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

// Valida, convierte e inserta un número individual en la pila
int	process_number(char *str, t_stack *stack)
{
	long long	val;
	t_node		*node;

	if (!is_valid_number(str) || !parse_long(str, &val)) // Evaluando sintaxis no numérica o desbordamiento
		return (0);
	if (is_duplicate(stack, (int)val)) // Evaluando duplicados
		return (0);
	node = stack_new_node((int)val);
	if (!node)
		return (0);
	stack_add_bottom(stack, node);
	return (1);
}

// Se imprime "Error\n" en el file descriptor 2 (stderr)
int	print_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

// Función auxiliar: recorre la matriz de números devuelta por ft_split
static int	process_split(char **split, t_stack *stack_a)
{
	int	j;

	if (!split || !split[0]) // Error 7, 8: falla del malloc interno o Cadena vacía
	{
		free_split(split);
		return (print_error());
	}
	j = 0;
	while (split[j])
	{
		if (!process_number(split[j], stack_a)) // Error 2, 3, 4, 5, 6: Sintaxis, overflow, duplicado
		{
			free_split(split);
			return (print_error());
		}
		j++;
	}
	free_split(split);
	return (1);
}

// Al hacer ft_split(argv[i], ' ') directamente sobre todos los argumentos 
// (ya vengan como "42" o como "42 100 -5"), se unifica la lógica:
// Si el argumento es un número solo (ej. "42"), ft_split devuelve un array de un solo 
// elemento ["42", NULL]. 
// Si el argumento contiene múltiples números (ej. "42 100 -5"), 
// devuelve ["42", "100", "-5", NULL].

// Función principal: itera la lista de argumentos y gestiona flags y splits
int	parse_arguments(int argc, char **argv, t_stack *stack_a, t_stats *stats)
{
	int	i;
	int	flag_st;

	i = 1;
	while (i < argc)
	{
		flag_st = check_flag(argv[i], stats);
		if (flag_st == -1) // Error 1: Flag inválido
			return (print_error());
		if (flag_st == 1)
		{
			i++;
			continue ;
		}
		if (!process_split(ft_split(argv[i], ' '), stack_a)) // Error: 2, 3, 4, 5, 6, 7, 8
			return (0);
		i++;
	}
	return (1);
}
