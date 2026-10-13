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

#include "../../include/push_swap.h"

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

// Libera la memoria de una matriz creada por ft_split, evitar fugas de memoria
// Bucle que hace free() a cada string secundario y luego al puntero principal split.
// ft_split divide una frase larga en varias palabras independientes. Por eso, necesitamos una lista (o array) de cadenas de texto.
// • char * = Una palabra (un puntero al primer carácter).
// • char ** = Una lista de palabras (un puntero que apunta a otros punteros).
void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);// Primero libera la memoria de la palabra en la posición i, una a una
		i++;
	}
	free(split);// al final se libera la memoria de la estructura lista que agrupaba las palabras
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
		return (0);// Ej: Si paso "-" en los argumentos, aquí invalida y da paso a imprimir error despues
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
int	parse_long(char *str, long long *out_value)
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
	*out_value = num * sign;
	return (1);
}


