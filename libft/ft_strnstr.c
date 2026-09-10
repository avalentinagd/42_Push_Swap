/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 22:15:37 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:33:46 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j < len) && little[j] == big[i + j] && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <bsd/string.h>
// int main(void)
// {
//     char *big =    "aaabcabcd"; 
//     // --- TEST 1: Caso normal para encontrar "cd" ---
//     printf("--- TEST 1 (len = 9 - Encuentra) ---\n");
//     printf("Tu ft    : >%s<\n", ft_strnstr(big, "cd", 9));
//     printf("Original : >%s<\n\n", strnstr(big, "cd", 9));

//     // --- TEST 2: Limite que corta ---
//     printf("--- TEST 2 (len = 8 - Corto) ---\n");
//     printf("Tu ft    : >%s<\n", ft_strnstr(big, "cd", 8));
//     printf("Original : >%s<\n\n", strnstr(big, "cd", 8));

//     // --- TEST 3: Aguja vacia ---
//     printf("--- TEST 3 (Aguja vacia) ---\n");
//     printf("Tu ft    : >%s<\n", ft_strnstr(big, "", 5));
//     printf("Original : >%s<\n\n", strnstr(big, "", 5));

//     // --- TEST 4: Coincidencia parcial ---
//     // Buscamos "abcde" donde solo existe "abcd"
//     printf("--- TEST 4 (Coincidencia parcial) ---\n");
//     printf("Tu ft    : >%s<\n", ft_strnstr(big, "abcde", 9));
//     printf("Original : >%s<\n\n", strnstr(big, "abcde", 9));

//     // --- TEST 5: len = 0 ---
//     printf("--- TEST 5 (len = 0) ---\n");
//     printf("Tu ft    : >%s<\n", ft_strnstr(big, "aa", 0));
//     printf("Original : >%s<\n\n", strnstr(big, "aa", 0));

//     // --- TEST 6: len = 0 ---
//     printf("--- TEST 6 (len = 0 y little = \'\\0') ---\n");
//     printf("Tu ft    : >%s<\n", ft_strnstr(big, "", 0));
//     printf("Original : >%s<\n\n", strnstr(big, "", 0));

//     return (0);
// }
