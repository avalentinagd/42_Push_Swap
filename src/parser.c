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

	if (!is_valid_number(str) || !parse_long(str, &val))
		return (0);
	if (is_duplicate(stack, (int)val))
		return (0);
	node = stack_new_node((int)val);
	if (!node)
		return (0);
	stack_add_bottom(stack, node);
	return (1);
}

// Procesa todos los argumentos recibidos por la línea de comandos
// Al hacer ft_split(argv[i], ' ') directamente sobre todos los argumentos 
// (ya vengan como "42" o como "42 100 -5"), se unifica la lógica:
// Si el argumento es un número solo (ej. "42"), ft_split devuelve un array de un solo 
// elemento ["42", NULL]. 
// Si el argumento contiene múltiples números (ej. "42 100 -5"), 
// devuelve ["42", "100", "-5", NULL].
int	parse_arguments(int argc, char **argv, t_stack *stack_a, t_stats *stats)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		if (check_flag(argv[i], stats))
		{
			i++;
			continue ;
		}
		split = ft_split(argv[i], ' ');
		if (!split || split_len(split) == 0)
		{
			free_split(split);
			return (0);
		}
		j = 0;
		while (split[j])
		{
			if (!process_number(split[j], stack_a))
			{
				free_split(split);
				return (0);
			}
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}
