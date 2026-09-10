/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:50:38 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/08 22:04:06 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*mem_str;
	int		len_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len_n = get_num_len(n);
	mem_str = malloc(len_n + 1);
	if (!mem_str)
		return (NULL);
	mem_str[len_n] = '\0';
	if (n == 0)
		mem_str[0] = '0';
	if (n < 0)
	{
		mem_str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		len_n--;
		mem_str[len_n] = (n % 10) + '0';
		n = n / 10;
	}
	return (mem_str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*res;

// 	// Test 1: El punto crítico absoluto (INT_MIN)
// 	res = ft_itoa(-2147483648);
// 	printf("Test 1 (INT_MIN) -> Esperado: -2147483648 | Obtenido: %s\n", res);
// 	free(res);

// 	// Test 2: El número Cero (Suele romper bucles mal controlados)
// 	res = ft_itoa(0);
// 	printf("Test 2 (Cero)    -> Esperado: 0           | Obtenido: %s\n", res);
// 	free(res);

// 	// Test 3: El número Máximo Positivo (INT_MAX)
// 	res = ft_itoa(2147483647);
// 	printf("Test 3 (INT_MAX) -> Esperado: 2147483647  | Obtenido: %s\n", res);
// 	free(res);

// 	// Test 4: Número negativo estándar
// 	res = ft_itoa(-42);
// 	printf("Test 4 (Negativo)-> Esperado: -42         | Obtenido: %s\n", res);
// 	free(res);

// 	// Test 5: Número positivo estándar de un solo dígito
// 	res = ft_itoa(7);
// 	printf("Test 5 (1 dígito)-> Esperado: 7           | Obtenido: %s\n", res);
// 	free(res);

// 	return (0);
// }
