/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 22:23:01 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:34:22 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if (uc >= 'a' && uc <= 'z')
		return (uc - 32);
	return (c);
}

// #include <stdio.h>
// int	toupper(int c);
// int	main(void)
// {
// 	int	c;

// 	c = ft_toupper('!');
// 	printf("Valor de entrada: !    ->  valor Obtendido: %c\n", c);
// 	c = ft_toupper('a');
// 	printf("Valor de entrada: a    ->  valor  Obtendido: %c\n", c);
// 	c = ft_toupper(-1);
// 	printf("Valor de entrada: -1   ->  valor Obtendido: %d\n", c);
// 	c = ft_toupper(255);
// 	printf("Valor de entrada: 255  ->  valor Obtendido: %d\n", c);
// 	c = ft_toupper(-65);
// 	printf("Valor de entrada: -65  ->  valor Obtendido: %d\n", c);
// 	c = ft_toupper('.');
// 	printf("Valor de entrada: .    ->  valor Obtendido: %c\n", c);
// 	c = ft_toupper('\0');
// 	printf("Valor de entrada: \\0   ->  valor Obtendido: %c\n", c);
// 	c = ft_toupper(0xFF);
// 	printf("Valor de entrada: 0xFF ->  valor Obtendido: %d\n", c);
// 	c = ft_toupper(0xE1);
// 	printf("Valor de entrada: 0xE1 ->  valor Obtendido: %d\n\n\n", c);
// 	{
// 		c = toupper('!');
// 		printf("Valor de entrada: !    ->  valor Obtendido: %c\n", c);
// 		c = toupper('a');
// 		printf("Valor de entrada: a    ->  valor Obtendido: %c\n", c);
// 		c = toupper(-1);
// 		printf("Valor de entrada: -1   ->  valor Obtendido: %d\n", c);
// 		c = toupper(255);
// 		printf("Valor de entrada: 255  ->  valor Obtendido: %d\n", c);
// 		c = toupper(-65);
// 		printf("Valor de entrada: -65  ->  valor Obtendido: %d\n", c);
// 		c = toupper('.');
// 		printf("Valor de entrada: .    ->  valor Obtendido: %c\n", c);
// 		c = toupper('\0');
// 		printf("Valor de entrada: \\0   ->  valor Obtendido: %c\n", c);
// 		c = toupper(0xFF);
// 		printf("Valor de entrada: 0xFF ->  valor Obtendido: %d\n", c);
// 		c = toupper(0xE1);
// 		printf("Valor de entrada: 0xE1 ->  valor Obtendido: %d\n", c);
// 	}
// 	return (0);
// }
