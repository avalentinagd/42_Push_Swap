/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 22:15:37 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/05 20:45:32 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_in_set(s1[end], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	char	*res;

// 	printf("--- TEST DE PUNTOS CRÍTICOS ---\n\n");

// 	// Test 1: Seguridad contra NULL (s1 es NULL)
// 	res = ft_strtrim(NULL, "123");
// 	printf("Test 1 (s1 NULL)    -> Esperado: (null)    | Obtenido: %s\n"
// 			, res);
// 	free(res);

// 	// Test 2: Seguridad contra NULL (set es NULL)
// 	res = ft_strtrim("Hola", NULL);
// 	printf("Test 2 (set NULL)   -> Esperado: (null)    | Obtenido: %s\n"
// 			, res);
// 	free(res);

// 	// Test 3: Cadena vacía
// 	res = ft_strtrim("", "abc");
// 	printf("Test 3 (S1 vacía)   -> Esperado: \"\"        | Obtenido: \"%s\"\n"
// 			, res);
// 	free(res);

// 	// Test 4: Cadena completamente llena con caracteres del set 
//				(Evita desbordamiento)
// 	res = ft_strtrim("   ", " ");
// 	printf("Test 4 (Todo set)   -> Esperado: \"\"        | Obtenido: \"%s\"\n"
// 			, res);
// 	free(res);

// 	// Test 5: Caso normal con recortes a ambos lados
// 	res = ft_strtrim("xxxHOLAxxx", "x");
// 	printf("Test 5 (Normal x)   -> Esperado: HOLA      | Obtenido: %s\n"
// 			, res);
// 	free(res);

// 	// Test 6: Set con múltiples caracteres y sin nada que recortar al final
// 	res = ft_strtrim(" \t \n42 Madrid", " \t\n");
// 	printf("Test 6 (Multi-set)  -> Esperado: 42 Madrid | Obtenido: %s\n"
// 			, res);
// 	free(res);

// 	return (0);
// }
