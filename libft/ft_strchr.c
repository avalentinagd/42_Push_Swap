/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:57:46 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/05 20:33:46 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c_char;

	c_char = (char)c;
	while (*s)
	{
		if (*s == c_char)
			return ((char *)s);
		s++;
	}
	if (*s == c_char)
		return ((char *)s);
	return (NULL);
}

//#include <stdio.h>
// int	main(void)
// {
// 	int		char_c;
// 	const char	*str;
// 	char		*dir_s;

// 	str = "hola";
// 	// Test 1: Buscar la 'o'
// 	char_c = 'o';
// 	dir_s = ft_strchr(str, char_c);
// 	printf("Busco 'o': Dirección: %p | Desde la 'o': %s\n", dir_s, dir_s);
// 	// // Test 2: Buscar el '\0' (Caso especial)
// 	char_c = '\0';
// 	dir_s = ft_strchr(str, char_c);
// 	printf("Busco '\\0': Dirección: %p | ¿Nulo?: %d\n", dir_s, *dir_s == '\0');
// 	return (0);
// }
