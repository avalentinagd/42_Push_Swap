/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 21:26:21 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/05 20:32:28 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;
	size_t	j;

	len_src = ft_strlen(src);
	len_dst = 0;
	while (dst[len_dst] != '\0' && len_dst < size)
		len_dst++;
	if (size <= len_dst)
		return (size + len_src);
	i = len_dst;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}

	//#include <stdio.h>
// int	main(void)
// {
// 	{
// 		char	dst1[30] = "Hola";
// 		char	*src1 = " Mundo";
// 		printf("%s\n", "CASO DE NORMAL ft");
// 		printf("Resultado retornado: %zu\n", ft_strlcat(dst1, src1, 15));
// 		printf("Contenido de dst: \"%s\"\n\n", dst1);
// 	}
// 	{
// 		char	dst11[30] = "Hola";
// 		char	*src11 = " Mundo";
// 		printf("%s\n", "CASO DE NORMAL Original");
// 		printf("Resultado retornado: %zu\n", strlcat(dst11, src11, 15));
// 		printf("Contenido de dst: \"%s\"\n\n", dst11);
// 	}
// 	{
// 		char	dst2[30] = "Hola";
// 		char	*src2 = " Mundo";
// 		size_t	size = 2;
// 		size_t	resultado = ft_strlcat(dst2, src2, size);
// 		printf("%s\n", "CASO DE DESBORDAMIENTO ft");
// 		printf("Resultado retornado: %zu\n", resultado);
// 		printf("Contenido de dst: \"%s\"\n\n", dst2);
// 	}
// 	{
// 		char	dst22[30] = "Hola";
// 		char	*src22 = " Mundo";
// 		size_t	size = 2;
// 		size_t	resultado = strlcat(dst22, src22, size);
// 		printf("%s\n", "CASO DE DESBORDAMIENTO Original");
// 		printf("Resultado retornado: %zu\n", resultado);
// 		printf("Contenido de dst: \"%s\"\n", dst22);
// 	}
// 	return (0);
// }
