/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 23:15:31 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/08 23:15:31 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Libera la memoria de una matriz creada por ft_split
// Bucle que hace free() a cada string secundario y luego al puntero principal split.
void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Cuenta la cantidad de elementos devueltos por un Split
size_t	split_len(char **split)
{
	size_t	i;

	if (!split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	return (i);
}

// Valida que la cadena contenga solo caracteres enteros
// entre '0' y '9', permitiendo opcionalmente un único signo + o - al comienzo.
int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// Convierte a long long y verifica que esté dentro del rango de un INT
// para prevenir desbordamientos (overflow/underflow)
// Replica un atoi, pero retorna un tipo long (64 bits). 
// Esto nos permite comparar si el valor obtenido supera los límites de un entero 
// de 32 bits (INT_MAX 2147483647 o INT_MIN -2147483648)
int	parse_long(char *str, long long *out_val)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((sign * num) > 2147483647 || (sign * num) < -2147483648)
			return (0); // Overflow / Underflow
		i++;
	}
	*out_val = num * sign;
	return (1);
}

double	compute_disorder(t_stack *stack_a)
{
	t_node	*i;
	t_node	*j;
	long	mistakes;
	long	total_pairs;

	if (!stack_a || stack_a->size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = stack_a->top;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs); // casteo a double: número decimal de precisión doble, evitando el error común de la división entera en C
}
