/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:57:46 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/05 20:37:52 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_char;
	char	*last;

	c_char = (char)c;
	last = NULL;
	while (*s)
	{
		if (*s == c_char)
			last = (char *)s;
		s++;
	}
	if (*s == c_char)
		last = (char *)s;
	return (last);
}

//#include <stdio.h>
// int	main(void)
// {
//     {
//         char *s;
//         s = "hola";
//         printf ("%s\n", "Test 1: carácter aparece una sola vez");
//         printf("Mi función: %s\n", ft_strrchr(s, 'o'));
//         printf("Original   : %s\n\n", strrchr(s, 'o'));
//     }
//     {
//         char *s;
//         s = "banana";
//         printf ("%s\n", "Test 2: varias apariciones");
//         printf("Mi función: %s\n", ft_strrchr(s, 'a'));
//         printf("Original   : %s\n\n", strrchr(s, 'a'));
//     }
//     {
//         char *s;
//         char *ptr1;
//         char *ptr2;
//         s = "banana";
//         ptr1 = ft_strrchr(s, 'z');
//         ptr2 = strrchr(s, 'z');
//         printf ("%s\n", "Test 3: carácter inexistente");
//         printf("Mi función: %p\n", ptr1);
//         printf("Original   : %p\n\n", ptr2);
//     }
//     {
//         char *s;
//         char *ptr1;
//         char *ptr2;
//         s = "banana";
//         ptr1 = ft_strrchr(s, '\0');
//         ptr2 = strrchr(s, '\0');
//         printf ("%s\n", "Test 4: buscar '\0'");
//         printf("Mi función: %p\n", ptr1);
//         printf("Original   : %p\n", ptr2);
//         printf("%p\n\n", s + ft_strlen(s));
//     }
//     {
//         char *s;
//         char *ptr1;
//         char *ptr2;
//         s = "";
//         ptr1 = ft_strrchr(s, '\0');
//         ptr2 = strrchr(s, '\0');
//         printf ("%s\n", "Test 5: string vacío + '\0'");
//         printf("Mi función: %p\n", ptr1);
//         printf("Original   : %p\n", ptr2);
//         printf("%p\n\n", s);
//     }
//     {
//         char *s;
//         s = "";
//         printf ("%s\n", "Test 6: string vacío + carácter normal");
//         printf("Mi función: %p\n", ft_strrchr(s, 'a'));
//         printf("Original   : %p\n\n", strrchr(s, 'a'));
//     }
//     {
//         char *s = "banana";
//         printf ("%s\n", "Test 7: comparar con la función original");
//         printf("Mi función: %p\n", ft_strrchr(s, 'a'));
//         printf("Original   : %p\n\n", strrchr(s, 'a'));
//     }
// }
