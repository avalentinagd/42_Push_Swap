/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:03:55 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:23:38 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\r'
		|| *nptr == '\t' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

// int main(void)
// {
//     // Caso 1: Casos estándar y ceros
//     printf("Original: %d | Tuya: %d\n", atoi("0"), ft_atoi("0"));
//     printf("Original: %d | Tuya: %d\n", atoi("42"), ft_atoi("42"));
//     printf("Original: %d | Tuya: %d\n\n", atoi("-42"), ft_atoi("-42"));

//     // Caso 2: Espacios raros y número negativo
//     printf("Original: %d | Tuya: %d\n", 
//             atoi(" \t-\n42"), ft_atoi(" \t-\n42"));
//     printf("Original: %d | Tuya: %d\n", atoi("42"), ft_atoi("42"));
//     printf("Original: %d | Tuya: %d\n\n", 
//             atoi("\t\n\v\f\r 42"), ft_atoi("\t\n\v\f\r 42"));

//     // Caso 3: Doble signo (Debe dar 0)
//     printf("Original: %d | Tuya: %d\n", atoi("--42"), ft_atoi("--42"));
//     printf("Original: %d | Tuya: %d\n", atoi("++42"), ft_atoi("++42"));
//     printf("Original: %d | Tuya: %d\n", atoi("+-42"), ft_atoi("+-42"));
//     printf("Original: %d | Tuya: %d\n\n", atoi("-+42"), ft_atoi("-+42"));

//     // Caso 4: Signo y luego espacio (Debe dar 0)
//     printf("Original: %d | Tuya: %d\n", atoi("- 42"), ft_atoi("- 42"));
//     printf("Original: %d | Tuya: %d\n\n", atoi("+ 42"), ft_atoi("+ 42"));

//     // Caso 5: Letras al principio (Debe dar 0)
//     printf("Original: %d | Tuya: %d\n\n", atoi("hola42"), ft_atoi("hola42"));

//     // Caso 6: Letras al final (Debe dar el número)
//     printf("Original: %d | Tuya: %d\n\n", atoi("42hola"), ft_atoi("42hola"));

//     // Caso 7: Espacio en medio de los números
//     printf("Original: %d | Tuya: %d\n\n", atoi("42  53"), ft_atoi("42  53"));

//     // Caso 8: Límites de los enteros (Int Max e Int Min)
//     printf("Original: %d | Tuya: %d\n", 
//             atoi("2147483647"), ft_atoi("2147483647"));
//     printf("Original: %d | Tuya: %d\n", 
//             atoi("-2147483648"), ft_atoi("-2147483648"));

//     return (0);
// }
