/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 00:12:54 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/02 23:34:15 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	uc;

	uc = (unsigned char) c;
	if (uc >= 'A' && uc <= 'Z')
		return (uc + 32);
	return (c);
}

// int	tolower(int c);
// int	main(void)
// {
// 	int	c;
//  {
// 		c = ft_tolower('!');
// 		printf("Valor de entrada: !    ->  valor Obtendido: %c\n", c);
// 		c = ft_tolower('A');
// 		printf("Valor de entrada: A    ->  valor  Obtendido: %c\n", c);
// 		c = ft_tolower(-1);
// 		printf("Valor de entrada: -1   ->  valor Obtendido: %d\n", c);
// 		c = ft_tolower(255);
// 		printf("Valor de entrada: 255  ->  valor Obtendido: %d\n", c);
// 		c = ft_tolower(-65);
// 		printf("Valor de entrada: -65  ->  valor Obtendido: %d\n", c);
// 		c = ft_tolower('.');
// 		printf("Valor de entrada: .    ->  valor Obtendido: %c\n", c);
// 		c = ft_tolower('\0');
// 		printf("Valor de entrada: \\0   ->  valor Obtendido: %c\n", c);
// 		c = ft_tolower(0xFF);
// 		printf("Valor de entrada: 0xFF ->  valor Obtendido: %d\n", c);
// 		c = ft_tolower(0xE1);
// 		printf("Valor de entrada: 0xE1 ->  valor Obtendido: %d\n\n\n", c);
//  }
// 	{
// 		c = tolower('!');
// 		printf("Valor de entrada: !    ->  valor Obtendido: %c\n", c);
// 		c = tolower('A');
// 		printf("Valor de entrada: A    ->  valor Obtendido: %c\n", c);
// 		c = tolower(-1);
// 		printf("Valor de entrada: -1   ->  valor Obtendido: %d\n", c);
// 		c = tolower(255);
// 		printf("Valor de entrada: 255  ->  valor Obtendido: %d\n", c);
// 		c = tolower(-65);
// 		printf("Valor de entrada: -65  ->  valor Obtendido: %d\n", c);
// 		c = tolower('.');
// 		printf("Valor de entrada: .    ->  valor Obtendido: %c\n", c);
// 		c = tolower('\0');
// 		printf("Valor de entrada: \\0   ->  valor Obtendido: %c\n", c);
// 		c = tolower(0xFF);
// 		printf("Valor de entrada: 0xFF ->  valor Obtendido: %d\n", c);
// 		c = tolower(0xE1);
// 		printf("Valor de entrada: 0xE1 ->  valor Obtendido: %d\n", c);
// 	}
// 	return (0);
// }