/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 22:15:37 by angalleg          #+#    #+#             */
/*   Updated: 2026/06/30 17:19:00 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
//     // Caso 1: Idénticas
//     printf("1. Identicas -> ori:  %d  | ft:  %d\n", 
//             memcmp("abcdef", "abcdef", 6), ft_memcmp("abcdef", "abcdef", 6));

//     // Caso 2: Pasando el \0 (Crucial)
//     printf("2. Tras \\0   -> ori: %d  | ft: %d\n", 
//             memcmp("abc\0X", "abc\0Y", 5), ft_memcmp("abc\0X", "abc\0Y", 5));

//     // Caso 3: n = 0
//     printf("3. n = 0     -> ori:  %d  | ft:  %d\n", 
//             memcmp("abc", "xyz", 0), ft_memcmp("abc", "xyz", 0));

//     // Caso 4: ASCII Extendido (Unsigned)
//     printf("4. Unsigned  -> ori:  %d  | ft:  %d\n", 
//             memcmp("\x80", "\x00", 1), ft_memcmp("\x80", "\x00", 1));

//     // --- CASO 5: Comparando tipos de datos que no son strings ---
//     int arr1[] = {1, 2, 3, 4};
//     int arr2[] = {1, 2, 5, 4};
//     printf("5. Arrays de enteros   -> ori: %d | ft: %d\n", 
//             memcmp(arr1, arr2, sizeof(int) * 4), 
//             ft_memcmp(arr1, arr2, sizeof(int) * 4));
// }
