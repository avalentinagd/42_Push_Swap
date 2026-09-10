/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:57:46 by angalleg          #+#    #+#             */
/*   Updated: 2026/06/25 17:07:51 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && (*s1 == *s2) && --n)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// strings iguales
// 	printf("Mi función: %d\n", ft_strncmp("hola", "hola", 3));
// 	printf("Original  : %d\n\n", strncmp("hola", "hola", 3));

// 	// n = 0
// 	printf("Mi función: %d\n", ft_strncmp("hola", "adios", 0));
// 	printf("Original  : %d\n\n", strncmp("hola", "adios", 0));

// 	// un str mas corto de n
// 	printf("Mi función: %d\n", ft_strncmp("123", "12345", 5));
// 	printf("Original  : %d\n\n", strncmp("123", "12345", 5));

// 	// caractres especiales / ASCII extendido
// 	printf("Mi función: %d\n", ft_strncmp("\200", "\0", 1));
// 	printf("Original  : %d\n\n", strncmp("\200", "\0", 1));

// 	// cadenas vacías
// 	printf("Mi función: %d\n", ft_strncmp("", "", 3));
// 	printf("Original  : %d\n\n", strncmp("", "", 3));

// 	return (0);
// }
