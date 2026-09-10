/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:50:38 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/08 22:48:39 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;
	size_t			len_s;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	new_str = malloc(len_s + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include <stdio.h>
// #include <stdlib.h>
// char	test_transform(unsigned int i, char c)
// {
// 	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
// 		return (c - 32); // Convierte a mayúscula en ASCII
// 	return (c);
// }

// int	main(void)
// {
// 	char	*res;

// 	// Test 1: Caso Normal
// 	res = ft_strmapi("hola mundo", test_transform);
// 	printf("Test 1 (Normal)  -> Esperado: HoLa mUnDo | Obtenido: %s\n", res);
// 	free(res);

// 	// Test 2: Cadena Vacía
// 	res = ft_strmapi("", test_transform);
// 	printf("Test 2 (Vacía)   -> Esperado: \"\"         | Obtenido: \"%s\"\n",
// 		 res);
// 	free(res);

// 	// Test 3: Protección NULL para la cadena
// 	res = ft_strmapi(NULL, test_transform);
// 	printf("Test 3 (s NULL)  -> Esperado: (null)    | Obtenido: %s\n", res);
// 	free(res);

// 	// Test 4: Protección NULL para la función
// 	res = ft_strmapi("test", NULL);
// 	printf("Test 4 (f NULL)  -> Esperado: (null)    | Obtenido: %s\n", res);
// 	free(res);

// 	return (0);
// }
