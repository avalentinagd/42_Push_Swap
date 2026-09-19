/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 02:31:02 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/07 02:31:02 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Función auxiliar básica para comparar dos cadenas
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// Comprueba si un argumento es una flag válida y actualiza las estadísticas
// Identifica las banderas obligatorias del proyecto. Devuelve 1 si era una bandera válida, 
// 0 si es un argumento numérico normal, y -1 si es un flag erróneo o desconocido.
// arg[0] == '-' && arg[1] == '-' para no confundir nros negativos con flags inválidos.
int check_flag(char *arg, t_stats *stats)
{
    if (ft_strcmp(arg, "--bench") == 0)
        stats->bench = 1;
    else if (ft_strcmp(arg, "--simple") == 0)
        stats->strategy_name = "Simple / O(n^2)";
    else if (ft_strcmp(arg, "--medium") == 0)
        stats->strategy_name = "Medium / O(n sqrt(n))";
    else if (ft_strcmp(arg, "--complex") == 0)
        stats->strategy_name = "Complex / O(n log n)";
    else if (ft_strcmp(arg, "--adaptive") == 0)
        stats->strategy_name = "Adaptive";
    else if (arg[0] == '-' && arg[1] == '-')
		return (-1); // Es un flag NO válida
    else
        return (0);  // No es una flag, es un número o entrada inválida
    return (1);      // Sí era una flag
}