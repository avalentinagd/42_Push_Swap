/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:31:00 by angalleg          #+#    #+#             */
/*   Updated: 2026/06/15 21:16:46 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// int	main(void)
// {
//     {
//         size_t result1;
//         char dst1[6];
//         result1 = ft_strlcpy(dst1, "abcdef", -6);
//         printf("%s\n", "CASO 1: dst1[6], src = 'abcdef', size = 6");
//         printf("%ld\n", result1);
//         printf("%s\n", &dst1[4]);
//         printf("%d\n\n", dst1[5]);
//     }
//     {
//         size_t result1;
//         char dst11[6];
//         result1 = strlcpy(dst11, "abcdef", -6);
//         printf("%s\n", "CASO 1: dst11[6], src = 'abcdef', size = 6");
//         printf("%ld\n", result1);
//         printf("%s\n", &dst11[4]);
//         printf("%d\n\n\n", dst11[5]);
//     }
//     {
//         size_t result3;
//         char dst2[1];
//         result3 = ft_strlcpy(dst2, "Hola", 1);
//         printf("%s\n", "CASO size = 1: dst2[1], src = 'Hola', size = 1");
//         printf("%ld\n", result3);
//         printf("%d\n\n", dst2[0]);
//     }
//     {
//         size_t result3;
//         char dst22[1];
//         result3 = strlcpy(dst22, "Hola", 1);
//         printf("%s\n", "CASO size = 1: dst22[1], src = 'Hola', size = 1");
//         printf("%ld\n", result3);
//         printf("%d\n", dst22[0]);
//     }
//     return (0);
// }
