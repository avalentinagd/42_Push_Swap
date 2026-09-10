/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:50:29 by angalleg          #+#    #+#             */
/*   Updated: 2026/06/10 18:07:43 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const unsigned char	src[] = "Hola mundo";
// 	unsigned char		ft[50];
// 	unsigned char		lib[50];

// 	ft_memcpy(ft, src, 11);
// 	memcpy(lib, src, 11);
// 	if (memcmp(ft, lib, 11) == 0)
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// 	return (0);
// }

/* I. Copia básica de una cadena */
	// char src[] = "Hola mundo";
	// char dst[20];
	// ft_memcpy(dst, src, strlen(src) + 1);

/* II. Copiar solo parte de la cadena */
	// char src[] = "abcdef";
	// char dst[10] = "XXXXXX";
	// ft_memcpy(dst, src, 3);

	// printf("%s\n", dst);

/* III. Copiar un array de enteros */
	// int src[] = {1, 2, 3, 4, 5};
	// int dst[5];
	// ft_memcpy(dst, src, sizeof(src));
	// for (int i = 0; i < 5; i++)
	//     printf("%d ", dst[i]);

/* IV. Copiar una estructura */
	// typedef struct s_person
	// {
	// 	int age;
	// 	char grade;
	// } t_person;
	// t_person a = {42, 'A'};
	// t_person b;
	// ft_memcpy(&b, &a, sizeof(t_person));
	// printf("%d %c\n", b.age, b.grade);

/* V. PARA n == 0 */
	// char src[] = "Hola";
	// char dst[] = "XXXX";
	// ft_memcpy(dst, src, 0);
	// printf("%s\n", dst);

/* VI. Destino y origen iguales */
	// char str[] = "abcdef";
	// ft_memcpy(str, str, 6);
	// printf("%s\n", str);

/* VII. Comprobar el valor de retorno */
	// char src[] = "abc";
	// char dst[10];
	// if (ft_memcpy(dst, src, 4) == dst)
	// 	printf("OK\n");

/* VIII. Copiar bytes nulos dentro de la memoria */
	// unsigned char src[5] = {1, 0, 2, 0, 3};
	// unsigned char dst[5];
	// ft_memcpy(dst, src, 5);
	// for (int i = 0; i < 5; i++)
	// 	printf("%d ", dst[i]);

/* IX. Comparación automática */
	// char src[] = "abcdefghijklmnopqrstuvwxyz";
	// char dst1[30];
	// char dst2[30];
	// ft_memcpy(dst1, src, 27);
	// memcpy(dst2, src, 27);
	// printf("%s\n", dst1);
	// printf("%s\n", dst2);

/* X. Probar muchos tamaños: Si no aparece nada, todo correcto. */
	// for (size_t n = 0; n < 100; n++)
	// {
	// 	char src[100];
	// 	char dst1[100];
	// 	char dst2[100];
	// 	memset(src, 'A', 100);
	// 	ft_memcpy(dst1, src, n);
	// 	memcpy(dst2, src, n);
	// 	if (memcmp(dst1, dst2, n))
	// 		printf("Error en n = %zu\n", n);
	// }

/* XI. Caso de memoria solapada (comportamiento indefinido) */
	// char str[] = "abcdef";
	// ft_memcpy(str + 2, str, 4);
	// printf("%s\n", str);

/* XII. Test clásico de Libft */
	// const unsigned char	src[] = "Hola mundo";
	// unsigned char	ft[50];
	// unsigned char	lib[50];

	// ft_memcpy(ft, src, 11);
	// memcpy(lib, src, 11);
	// if (memcmp(ft, lib, 11) == 0)
	// 	printf("OK\n");
	// else
	// 	printf("KO\n");
	// return(0);
