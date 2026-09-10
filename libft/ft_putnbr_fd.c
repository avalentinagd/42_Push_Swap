/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:50:38 by angalleg          #+#    #+#             */
/*   Updated: 2026/07/08 22:17:15 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd((int)(nbr / 10), fd);
	}
	ft_putchar_fd((nbr % 10) + '0', fd);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("Test 1 (Positivo) -> Esperado: 42 | Obtenido: ");
// 	ft_putnbr_fd(42, 1);
// 	printf("\n\n");

// 	printf("Test 2 (Cero)     -> Esperado: 0 | Obtenido: ");
// 	ft_putnbr_fd(0, 1);
// 	printf("\n\n");

// 	printf("Test 3 (Negativo) -> Esperado: -2147483648 | Obtenido: ");
// 	ft_putnbr_fd(-2147483648, 1);
// 	printf("\n");

// 	return (0);
// }
