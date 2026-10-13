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

#include "../../include/push_swap.h"

// Función auxiliar básica para comparar dos cadenas
// const: indica que esta función va a leer el contenido de s1, pero promete no modificarlo
// Si no tuviera const, al hacer esto ft_strcmp(arg, "--bench"), el compilador daría un warning o error de incompatibilidad de tipos.
// También, aseguramos que ft_strcmp se comporte exactamente igual si compilamos en macOS, en Linux o en cualquier otra arquitectura
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
    // strcmp exige que los caracteres se comparen como si fueran valores sin signo (unsigned)
    // Evita problemas con caracteres extendidos (ASCII Alto / UTF-8)
    // unsigned asegura que todos los caracteres vayan de 0 a 255, garantizando que los caracteres extendidos siempre sean detectados como "mayores" que los caracteres ASCII estándar.
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
        stats->strategy_name = "Complex / O(n log(n))";
    else if (ft_strcmp(arg, "--adaptive") == 0)
        stats->strategy_name = "Adaptive";
    else if (arg[0] == '-' && arg[1] == '-') // Si el argumento no coincidió con ninguna bandera válida, pero empieza por "--", la función detecta que es una bandera desconocida y devuelve -1 (indicando error de sintaxis)
		return (-1); // Es un flag NO válida
    else
        return (0);  // No es una flag, es un número o entrada inválida
    return (1);      // Sí era una flag
}