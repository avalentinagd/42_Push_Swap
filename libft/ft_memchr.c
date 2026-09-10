/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:24:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:32:33 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*uchar;
	unsigned char	new_c;

	uchar = (unsigned char *)s;
	new_c = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (n)
	{
		if (*uchar == new_c)
			return ((void *)uchar);
		uchar++;
		n--;
	}
	return (NULL);
}

// #include <stdio.h>
// int main (void)
// {
//     char str[] = "Hola Mundo, 42 Madrid!";

//     // Caso 1: Buscar un carácter común que sí existe
//     printf("Caso 1 (Buscar 'M'):\n");
//     printf("  Original  : %p\n", memchr(str, 'M', 15));
//     printf("  Mi función: %p\n\n", ft_memchr(str, 'M', 15));

//     // Caso 2: Buscar un carácter que NO está en el rango de 'n'
//     printf("Caso 2 (Buscar 'M' pero n es corto):\n");
//     printf("  Original  : %p\n", memchr(str, 'M', 3));
//     printf("  Mi función: %p\n\n", ft_memchr(str, 'M', 3));

//     // Caso 3: Buscar con n = 0
//     printf("Caso 3 (n = 0):\n");
//     printf("  Original  : %p\n", memchr(str, 'H', 0));
//     printf("  Mi función: %p\n\n", ft_memchr(str, 'H', 0));

//     // Caso 4: Overflow de int (300 se convierte en el carácter ',')
//     printf("Caso 4 (Overflow int 300):\n");
//     printf("  Original  : %p\n", memchr(str, 300, 20));
//     printf("  Mi función: %p\n\n", ft_memchr(str, 300, 20));

//     // Caso 5: Buscar el byte nulo '\0'
//     printf("Caso 5 (Buscar '\\0'):\n");
//     printf("  Original  : %p\n", memchr(str, '\0', 23));
//     printf("  Mi función: %p\n", ft_memchr(str, '\0', 23));

//     return (0);
// }
