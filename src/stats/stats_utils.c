/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalleg <angalleg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:01:46 by angalleg          #+#    #+#             */
/*   Updated: 2026/09/29 00:01:46 by angalleg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Función auxiliar para imprimir strings en stderr (fd 2)
void    ft_putstr_stderr(char *str)
{
    int i;

    if (!str)
        return ;
    i = 0;
    while (str[i])
        i++;
    write(2, str, i); // write con fd = 2 escribe en stderr
}

// Función auxiliar para imprimir enteros en stderr (fd 2)
void	ft_putnbr_stderr(int n)
{
	char	c;

	if (n < 0)
	{
		ft_putstr_stderr("-");
		if (n == -2147483648)
		{
			ft_putstr_stderr("2147483648");
			return ;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_stderr(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

// Imprime un número entre 0.00% y 100.00% usando ft_putstr_stderr y ft_putnbr_stderr
void	ft_putdouble_stderr(double num)
{
	long	entera;
	long	decimal;

	// Redondeo clásico a 2 decimales para evitar problemas de precisión flotante
	num = num + 0.005;
	entera = (long)num;
	decimal = (long)((num - entera) * 100);
	
	// Imprimimos la parte entera (será un número entre 0 y 100)
	ft_putnbr_stderr(entera);
	ft_putstr_stderr(".");
	
	// Si el residuo decimal es menor a 10 (ej: .05), forzamos el cero a la izquierda
	if (decimal < 10)
		ft_putstr_stderr("0");
	ft_putnbr_stderr(decimal);
}
